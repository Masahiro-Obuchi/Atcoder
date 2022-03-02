#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
/*
struct Edge
{
  ll to;
  ll weight;
  Edge(ll t, ll w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
*/
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

uint64_t get_rand_range(uint64_t min_val, uint64_t max_val)
{
  // 乱数生成器
  static std::mt19937_64 mt64(0);

  // [min_val, max_val] の一様分布整数 (int) の分布生成器
  std::uniform_int_distribution<uint64_t> get_rand_uni_int(min_val, max_val);

  // 乱数を生成
  return get_rand_uni_int(mt64);
}

double get_rand_range_real(double min_val, double max_val)
{
  // 乱数生成器
  static std::mt19937_64 mt64(0);

  // [min_val, max_val] の一様分布整数 (int) の分布生成器
  std::uniform_real_distribution<double> get_rand_real(min_val, max_val);

  // 乱数を生成
  return get_rand_real(mt64);
}

const int DR[4] = {1, 0, -1, 0};
const int DC[4] = {0, 1, 0, -1};

struct Vegetable
{
  int r, c, s, e, v;
  Vegetable(int r_, int c_, int s_, int e_, int v_)
      : r(r_), c(c_), s(s_), e(e_), v(v_)
  {
  }
};

struct Action
{
  vector<int> vs;

private:
  explicit Action(const vector<int> &vs_) : vs(vs_) {}

public:
  static Action pass()
  {
    return Action({-1});
  }

  static Action purchase(int r, int c)
  {
    return Action({r, c});
  }

  static Action move(int r1, int c1, int r2, int c2)
  {
    return Action({r1, c1, r2, c2});
  }
};

int N, M, T;
vector<vector<Vegetable>> veges_start; // veges_start[i] : vegetables appear on day i
vector<vector<Vegetable>> veges_end;   // veges_end[i] : vegetables disappear on day i

struct Game
{
  vector<vector<int>> has_machine;
  vector<vector<int>> vege_values;
  vector<vector<int>> order;
  int num_machine;
  int next_price;
  int money;

  // add
  int core_r;
  int core_c;
  int prev_r;
  int prev_c;

  // 購入直後かどうか
  bool justAfterPurchace;

  Game() : num_machine(0), next_price(1), money(1), core_r(-1), core_c(-1), prev_r(-1), prev_c(-1), justAfterPurchace(0)
  {
    has_machine.assign(N, vector<int>(N, 0));
    vege_values.assign(N, vector<int>(N, 0));

    vector<int> vec(4);
    iota(vec.begin(), vec.end(), 0);
    do
    {
      vector<int> tmp;
      for (auto it : vec)
      {
        tmp.push_back(it);
      }
      order.push_back(tmp);
    } while (next_permutation(vec.begin(), vec.end()));
  }

  void purchase(int r, int c)
  {
    assert(!has_machine[r][c]);
    assert(next_price <= money);
    has_machine[r][c] = 1;
    money -= next_price;
    num_machine++;
    next_price = (num_machine + 1) * (num_machine + 1) * (num_machine + 1);
  }

  void move(int r1, int c1, int r2, int c2)
  {
    assert(has_machine[r1][c1]);
    has_machine[r1][c1] = 0;
    assert(!has_machine[r2][c2]);
    has_machine[r2][c2] = 1;
  }

  void simulate(int day, const Action &action)
  {
    if (!day)
    {
      // appear
      for (const Vegetable &vege : veges_start[day])
      {
        vege_values[vege.r][vege.c] = vege.v;
      }
    }

    // apply
    if (action.vs.size() == 2)
    {
      purchase(action.vs[0], action.vs[1]);
    }
    else if (action.vs.size() == 4)
    {
      move(action.vs[0], action.vs[1], action.vs[2], action.vs[3]);
    }

    // harvest
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (has_machine[i][j] && vege_values[i][j] > 0)
        {
          money += vege_values[i][j] * count_connected_machines(i, j);
          vege_values[i][j] = 0;
        }
      }
    }

    // disappear
    for (const Vegetable &vege : veges_end[day])
    {
      vege_values[vege.r][vege.c] = 0;
    }

    // appear
    if (day + 1 < 1000)
    {
      for (const Vegetable &vege : veges_start[day + 1])
      {
        vege_values[vege.r][vege.c] = vege.v;
      }
    }
  }

  int count_connected_machines(int r, int c)
  {
    vector<pair<int, int>> queue = {{r, c}};
    vector<vector<int>> visited(N, vector<int>(N, 0));
    visited[r][c] = 1;
    int i = 0;
    while (i < (int)queue.size())
    {
      int cr = queue[i].first;
      int cc = queue[i].second;
      for (int dir = 0; dir < 4; dir++)
      {
        int nr = cr + DR[dir];
        int nc = cc + DC[dir];
        if (0 <= nr && nr < N && 0 <= nc && nc < N && has_machine[nr][nc] && !visited[nr][nc])
        {
          visited[nr][nc] = 1;
          queue.push_back({nr, nc});
        }
      }
      i++;
    }
    return i;
  }

  Action select_next_action(int day)
  {
    vector<vector<int>> sum_future_veges(N, vector<int>(N, 1));
    // int future_scope_min = day + 1, future_scope_max = day + 4 * day / 5 + 200;
    // int future_scope = get_rand_range(future_scope_min, future_scope_max);
    /*
        for (int i = day; i < min(future_scope, T); i++)
        {
            for (const Vegetable &vege : veges_start[i])
            {
                sum_future_veges[vege.r][vege.c] += vege.v;
            }
        }
        */
    for (int i = 0; i < T; i++)
    {
      for (const Vegetable &vege : veges_start[i])
      {
        sum_future_veges[vege.r][vege.c] += vege.v;
      }
    }

    int now_connect_max = -1;
    for (int r = 0; r < N; r++)
    {
      for (int c = 0; c < N; c++)
      {
        if (has_machine[r][c])
          now_connect_max = max(now_connect_max, count_connected_machines(r, c));
      }
    }

    int max_purchase_day = 900;
    int max_purchase_num_machine = 50;
    // implement your strategy here
    if (money < next_price || num_machine >= 50)
    {
      cerr << "day: " << day << endl;
      // moveはただ現在価値が最も高い野菜が存在する場所にmove_rとmove_cを動かしてmove_rとmove_cを更新するだけ 950以上の場合は連結数が1のやつを連結させる
      // 連結するように動かしたときと価値最大の野菜のどちらが儲かるかを評価して動く先を決める
      // 後半になってきたらvalueがでかいものも考慮して買うようにする

      // 移動しても連結数が1しか減らないかつ直近で最も稼ぎが低いマスから、多点bfsをして消滅までにたどり着ける最も高い野菜に近づく方向に移動する
      int future_scope;
      if (num_machine <= 1)
        future_scope = 1;
      else
        future_scope = 30;
      // これは調整する
      vector<vector<int>> near_future_veges(N, vector<int>(N, 1));
      // int future_scope_min = day + 1, future_scope_max = day + 4 * day / 5 + 200;
      // int future_scope = get_rand_range(future_scope_min, future_scope_max);
      for (int i = day; i < min(day + future_scope, T); i++)
      {
        for (const Vegetable &vege : veges_start[i])
        {
          near_future_veges[vege.r][vege.c] += vege.v;
        }
      }

      vector<pair<int, P>> weakMachine;
      // 動かしても連結が保たれるマシンを選ぶ
      for (int r = 0; r < N; r++)
      {
        for (int c = 0; c < N; c++)
        {
          if (!has_machine[r][c])
            continue;
          has_machine[r][c] = 0;
          bool ok = false;
          for (int i = 0; i < 4; i++)
          {
            int nr = r + dy[i], nc = c + dx[i];
            if (0 <= nr && nr < N && 0 <= nc && nc < N && has_machine[nr][nc])
            {
              if (count_connected_machines(nr, nc) == now_connect_max - 1)
                ok = true;
            }
          }
          has_machine[r][c] = 1;

          if (num_machine == 1)
            weakMachine.push_back({near_future_veges[r][c], {r, c}});
          else if (ok)
            weakMachine.push_back({near_future_veges[r][c], {r, c}});
        }
      }

      // sort(weakMachine.begin(), weakMachine.end());

      int move_r = -1, move_c = -1;
      if (weakMachine.size())
      {
        // move_r = weakMachine[0].second.first, move_c = weakMachine[0].second.second;
        int idx = get_rand_range(0, weakMachine.size() - 1);
        move_r = weakMachine[idx].second.first, move_c = weakMachine[idx].second.second;
      }

      if (move_r == -1 && move_c == -1)
        return Action::pass();

      // 多点bfsを行って何マスで到達出来るか調べる
      vector<vector<int>> dist(N, vector<int>(N, -1));
      queue<P> que;
      for (int r = 0; r < N; r++)
      {
        for (int c = 0; c < N; c++)
        {
          if (has_machine[r][c])
          {
            dist[r][c] = 0;
            que.push({r, c});
          }
        }
      }

      while (!que.empty())
      {
        auto cur = que.front();
        que.pop();
        for (int dir = 0; dir < 4; dir++)
        {
          int nr = cur.first + dy[dir], nc = cur.second + dx[dir];
          if (0 <= nr && nr < N && 0 <= nc && nc < N && !has_machine[nr][nc])
          {
            if (dist[nr][nc] == -1)
            {
              dist[nr][nc] = dist[cur.first][cur.second] + 1;
              que.push({nr, nc});
            }
          }
        }
      }

      vector<vector<bool>> dispairVegetable(N, vector<bool>(N, false));
      for (int i = day; i < min(T, day + future_scope - 1); i++)
      {
        for (const Vegetable &vege : veges_end[i])
        {
          dispairVegetable[vege.r][vege.c] = true;
        }
      }

      // targetを探索
      int target_max = 0;
      int target_r = -1, target_c = -1;
      for (int r = 0; r < N; r++)
      {
        for (int c = 0; c < N; c++)
        {
          if (num_machine == 1)
          {
            if (!has_machine[r][c] && target_max <= vege_values[r][c])
            {
              target_max = near_future_veges[r][c];
              target_r = r, target_c = c;
            }
          }
          else
          {
            //if (!has_machine[r][c] && !dispairVegetable[r][c] && dist[r][c] < future_scope && target_max <= near_future_veges[r][c])
            if (!has_machine[r][c] && target_max <= near_future_veges[r][c] / dist[r][c])
            {
              target_max = near_future_veges[r][c] / dist[r][c];
              target_r = r, target_c = c;
            }
          }
        }
      }

      cerr << "target_r: " << target_r << "  target_c:  " << target_c << "  target_max: " << target_max << endl;

      // distが1かつtargetとのマンハッタン距離最小のマスを選ぶ
      // target_rとtarget_cは毎回変わってしまうから1歩で判断できるなにか別の指標を持ってくる
      int next_r = -1, next_c = -1;
      int minDist = INT_INF;
      for (int r = 0; r < N; r++)
      {
        for (int c = 0; c < N; c++)
        {
          if (num_machine == 1)
          {
            if (vege_values[r][c] == target_max)
            {
              next_r = target_r, next_c = target_c;
            }
          }
          else
          {
            if (has_machine[r][c])
              continue;
            has_machine[move_r][move_c] = 0;
            has_machine[r][c] = 1;
            int now_dist = abs(r - target_r) + abs(c - target_c);
            int now_connects = count_connected_machines(r, c);
            if (now_connects == now_connect_max && now_dist <= minDist && (r != prev_r || c != prev_c))
            {
              minDist = now_dist;
              next_r = r, next_c = c;
            }
            has_machine[r][c] = 0;
            has_machine[move_r][move_c] = 1;
          }
        }
      }

      cerr << "move_r: " << move_r << "  move_c: " << move_c << "  next_r:  " << next_r << "  next_c:  " << next_c << endl;
      // 動かす
      prev_r = move_r, prev_c = move_c;
      if (((move_r != next_r) || (move_c != next_c)) && next_r != -1 && next_c != -1)
        return Action::move(move_r, move_c, next_r, next_c);
      else
      {
        return Action::pass();
      }
    }
    else
    {
      if (num_machine == 0)
      {
        vector<vector<int>> sum_future_veges(N, vector<int>(N, 0));
        for (int i = day; i < day + 1; i++)
        {
          for (const Vegetable &vege : veges_start[i])
          {
            sum_future_veges[vege.r][vege.c] += vege.v;
          }
        }

        int max_value = 0;
        int max_r = -1, max_c = -1;
        for (int r = 0; r < N; r++)
        {
          for (int c = 0; c < N; c++)
          {
            if (has_machine[r][c])
              continue;
            if (max_value < sum_future_veges[r][c])
            {
              max_value = sum_future_veges[r][c];
              max_r = r;
              max_c = c;
            }
          }
        }

        if (max_r != -1 && max_c != -1)
        {
          justAfterPurchace = true;
          return Action::purchase(max_r, max_c);
        }
        else
        {
          return Action::pass();
        }
      }
      else
      {
        // それ以外
        // 連結が保たれるように今後の価値が最も高いマスで購入する　かつmove_rとmove_c以外と連結になることを確認する（上下4マスを調べてmove_rとmove_c以外で連結数が3以上になっていることを確認する）

        vector<P> replaceCandidate;
        for (int r = 0; r < N; r++)
        {
          for (int c = 0; c < N; c++)
          {
            if (has_machine[r][c])
              continue;
            has_machine[r][c] = 1;
            int now_connect_value = count_connected_machines(r, c);
            if (now_connect_value == now_connect_max + 1)
            {
              bool ok = false;
              for (int i = 0; i < 4; i++)
              {
                int adj_r = r + dy[i], adj_c = c + dx[i];
                if (0 <= adj_r && adj_r < N && 0 <= adj_c && adj_c < N && has_machine[adj_r][adj_c])
                {
                  int adj_connect_cnt = count_connected_machines(r, c);
                  if (adj_connect_cnt >= 2)
                    ok = true;
                }
              }

              if (ok)
                replaceCandidate.push_back({r, c});
            }
            has_machine[r][c] = 0;
          }
        }

        int max_value = 0;
        int max_r = -1, max_c = -1;
        for (auto [r, c] : replaceCandidate)
        {
          if (has_machine[r][c])
            continue;
          if (max_value < sum_future_veges[r][c])
          {
            max_value = sum_future_veges[r][c];
            max_r = r;
            max_c = c;
          }
        }

        if (max_value > 0 && max_r != -1 && max_c != -1 && num_machine < max_purchase_num_machine)
        {
          justAfterPurchace = true;
          return Action::purchase(max_r, max_c);
        }
        else
        {
          return Action::pass();
        }
      }
    }
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 1; i < 147; i++)
    cerr << i * i * i << endl;

  cin >> N >> M >> T;
  veges_start.resize(T);
  veges_end.resize(T);
  for (int i = 0; i < M; i++)
  {
    int r, c, s, e, v;
    cin >> r >> c >> s >> e >> v;
    Vegetable vege(r, c, s, e, v);
    veges_start[s].push_back(vege);
    veges_end[e].push_back(vege);
  }
  Game game;
  vector<Action> actions;
  for (int day = 0; day < T; day++)
  {
    Action action = game.select_next_action(day);
    actions.push_back(action);
    game.simulate(day, action);
  }
  for (const Action &action : actions)
  {
    for (int i = 0; i < action.vs.size(); i++)
    {
      cout << action.vs[i] << (i == action.vs.size() - 1 ? "\n" : " ");
    }
  }
  return 0;
}
