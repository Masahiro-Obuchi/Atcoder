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

    int move_r;
    int move_c;

    // 購入直後かどうか
    bool justAfterPurchace;

    Game() : num_machine(0), next_price(1), money(1), core_r(-1), core_c(-1), move_r(-1), move_c(-1), justAfterPurchace(0)
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
        // apply
        if (action.vs.size() == 2)
        {
            purchase(action.vs[0], action.vs[1]);
        }
        else if (action.vs.size() == 4)
        {
            move(action.vs[0], action.vs[1], action.vs[2], action.vs[3]);
        }
        // appear
        for (const Vegetable &vege : veges_start[day])
        {
            vege_values[vege.r][vege.c] = vege.v;
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
        int future_scope_min = day + 1, future_scope_max = day + 4 * day / 5 + 200;
        int future_scope = get_rand_range(future_scope_min, future_scope_max);
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

        int max_purchase_day = 950;
        // implement your strategy here
        if (money < next_price)
        {

            cerr << "day: " << day << endl;
            // moveはただ現在価値が最も高い野菜が存在する場所にmove_rとmove_cを動かしてmove_rとmove_cを更新するだけ 950以上の場合は連結数が1のやつを連結させる
            // 連結するように動かしたときと価値最大の野菜のどちらが儲かるかを評価して動く先を決める
            // 何故かday == 0のときpassされるのと謎にpassされるときがある
            // テストを一気に回すシェルスクリプトを書く
            // 後半になってきたらvalueがでかいものも考慮して買うようにする

            // マシンが連結になっていないマスの中で最も価値が高い野菜が生えてくる場所とその価値
            int mostVariableVegetable = 0;
            int next_r = -1, next_c = -1;
            for (int r = 0; r < N; r++)
            {
                for (int c = 0; c < N; c++)
                {
                    if (has_machine[r][c])
                        continue;
                    if (mostVariableVegetable < vege_values[r][c])
                    {
                        mostVariableVegetable = vege_values[r][c];
                        next_r = r, next_c = c;
                    }
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

            vector<pair<int, P>> nextCandidate;
            for (int r = 0; r < N; r++)
            {
                for (int c = 0; c < N; c++)
                {
                    if (has_machine[r][c])
                        continue;
                    has_machine[r][c] = 1;
                    int now_connect_value = count_connected_machines(r, c);
                    if (now_connect_value == now_connect_max + 1 && (abs(r - move_r) > 1 || abs(c - move_c) > 1))
                        nextCandidate.push_back({vege_values[r][c], {r, c}});
                    has_machine[r][c] = 0;
                }
            }

            if (get_rand_range_real(0.0, 1.0) > 0.2)
            {
                if (nextCandidate.size() > 0)
                {
                    int idx = get_rand_range(0, (int)nextCandidate.size() - 1);
                    int arg_r1 = move_r, arg_c1 = move_c;
                    int next_r = nextCandidate[idx].second.first, next_c = nextCandidate[idx].second.second;
                    move_r = next_r, move_c = next_c;
                    return Action::move(arg_r1, arg_c1, next_r, next_c);
                }
            }
            else
            {
                if (next_r != -1 && next_c != -1 && move_r != -1 && move_c != -1)
                {
                    int arg_r1 = move_r, arg_c1 = move_c;
                    move_r = next_r, move_c = next_c;
                    return Action::move(arg_r1, arg_c1, next_r, next_c);
                }
            }
            return Action::pass();
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

                move_r = max_r, move_c = max_c;

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
            else if (num_machine == 1)
            {
                // 2個目の購入のとき
                // 3x3の区画の集合の中で最も価値が高い区画を探す
                int maxSumOf3x3CellsValue = 0;
                int center_r = -1, center_c = -1;
                for (int r = 2; r < N - 2; r++)
                {
                    for (int c = 2; c < N - 2; c++)
                    {
                        int sumOfValue = 0;
                        for (int i = -2; i <= 2; i++)
                        {
                            for (int j = -2; j <= 2; j++)
                            {
                                sumOfValue += sum_future_veges[r + i][c + j];
                            }
                        }
                        if (maxSumOf3x3CellsValue < sumOfValue)
                        {
                            maxSumOf3x3CellsValue = sumOfValue;
                            center_r = r, center_c = c;
                        }
                    }
                }

                // 更にその区画の中で最も稼げるマスを探す（ここのスコープは後で調整する、最初の方は近めだけを見たほうがいい？）
                int maxValueCells = 0;
                for (int i = -2; i <= 2; i++)
                {
                    for (int j = -2; j <= 2; j++)
                    {
                        if (maxValueCells < sum_future_veges[center_r + i][center_c + j])
                        {
                            maxValueCells = sum_future_veges[center_r + i][center_c + j];
                            core_r = center_r + i, core_c = center_c + j;
                        }
                    }
                }
                if (maxValueCells > 0 && core_r != -1 && core_c != -1)
                {
                    justAfterPurchace = true;
                    return Action::purchase(core_r, core_c);
                }
                else
                {
                    return Action::pass();
                }
            }
            else if (num_machine == 2)
            {
                // 3個目を購入するときにcore_rとcore_cのマスと必ず連結になるようにする
                int max_value = 0;
                int max_r = -1, max_c = -1;
                for (int i = 0; i < 4; i++)
                {
                    int now_r = core_r + dy[i], now_c = core_c + dx[i];
                    if (0 <= now_r && now_r < N && 0 <= now_c && now_c < N)
                    {
                        if (has_machine[now_r][now_c])
                            continue;
                        if (sum_future_veges[now_r][now_c] >= max_value)
                        {
                            max_r = now_r, max_c = now_c;
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
                int now_connect_max = -1;
                for (int r = 0; r < N; r++)
                {
                    for (int c = 0; c < N; c++)
                    {
                        if (has_machine[r][c])
                            now_connect_max = max(now_connect_max, count_connected_machines(r, c));
                    }
                }

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
                                if (0 <= adj_r && adj_r < N && 0 <= adj_c && adj_c < N && r != move_r && c != move_c)
                                {
                                    int adj_connect_cnt = count_connected_machines(r, c);
                                    if (adj_connect_cnt >= 3)
                                        ok = true;
                                }
                            }

                            if (ok)
                                replaceCandidate.push_back({r, c});
                        }
                        has_machine[r][c] = 0;
                    }
                }

                if (replaceCandidate.size() > 0)
                {
                    int idx = get_rand_range(0, (int)replaceCandidate.size() - 1);
                    int purchase_r = replaceCandidate[idx].first, purchase_c = replaceCandidate[idx].second;
                    return Action::purchase(purchase_r, purchase_c);
                }
                else
                {
                    return Action::pass();
                }
            }
        }
    }
};

class State
{
public:
    State() : score(0), day(0){};

    // 評価関数
    void Eval()
    {
        // 連結数、現在のマネー、現在の機械の数、1マスで到達可能なマス数（、その盤面で何点取れるか）の重み付き和
        int now_connect_max = 0;
        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < N; c++)
            {
                now_connect_max = max(now_connect_max, game.count_connected_machines(r, c));
            }
        }
        score = game.money + 100 * game.num_machine + 100 * day * now_connect_max;
        return;
    };

    bool operator<(const State &state)
    {
        return score < state.score;
    };

    int day;
    int score;
    Game game;
    vector<Action> actions;
};

// 計算量改善: priority_queue4つによる代用
State beamSearch(int beamWidth)
{
    // ビームサーチ用
    deque<State> beam;

    // 次のイテレーション用
    deque<State> nexts;

    // 初期状態(0日目)を作成 最初のマスの選び方を網羅する
    State state;
    Action action = state.game.select_next_action(0);
    state.actions.push_back(action);
    state.game.simulate(0, action);
    beam.push_front(state);

    for (int day = 1; day < 1000; day++)
    {
        cerr << "day: " << day << endl;
        while (!beam.empty())
        {
            State state = beam.front();
            beam.pop_front();
            for (int t = 0; t < 3; t++)
            {
                State copyState = state;
                Action action = copyState.game.select_next_action(day);
                copyState.actions.push_back(action);
                copyState.game.simulate(day, action);
                // 現在の状態を評価する
                copyState.Eval();
                nexts.push_back(copyState);
            }
        }

        sort(nexts.begin(), nexts.end());

        // 評価値が高いものをビーム幅分キューに追加
        for (int i = 0; i < beamWidth && !nexts.empty(); i++)
        {
            beam.push_back(nexts.back());
            nexts.pop_back();
        }
        nexts.clear();
    }

    // 最後にスコア順にソート
    sort(beam.begin(), beam.end());

    // 最も良い状態を返す
    return beam.back();
}

void outputSolution(const State &state)
{
    for (const Action &action : state.actions)
    {
        for (int i = 0; i < action.vs.size(); i++)
        {
            cout << action.vs[i] << (i == action.vs.size() - 1 ? "\n" : " ");
        }
    }
    return;
}

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

    State bestState = beamSearch(10);
    outputSolution(bestState);

    return 0;
}
