#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct Edge
{
  ll to;
  ll weight;
  Edge(ll t, ll w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;

// using Graph = vector<vector<int>>;

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

double get_rand_normal(double ave, double stddev)
{
  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());

  std::normal_distribution<> dist(ave, stddev);
  return dist(engine);
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

void genInitGrid(Graph &G, vector<vector<ll>> &h, vector<vector<ll>> &v)
{
  cerr << "Init start" << endl;
  ll D = get_rand_range(100, 2000), M = get_rand_range(1, 2);
  cerr << "D: " << D << "   M: " << M << endl;

  // x方向の初期距離の決定
  vector<vector<ll>> H(30, vector<ll>(M));
  for (int i = 0; i < 30; i++)
  {
    for (int j = 0; j < M; j++)
    {
      H[i][j] = get_rand_range(1000 + D, 9000 - D);
    }
  }

  vector<vector<ll>> x(30, vector<ll>(M + 1));
  if (M == 2)
  {
    for (int i = 0; i < 30; i++)
    {
      x[i][0] = 0, x[i][M] = 29;
      x[i][1] = get_rand_range(1, 28);
    }
  }
  else
  {
    for (int i = 0; i < 30; i++)
    {
      x[i][0] = 0, x[i][M] = 29;
    }
  }

  vector<vector<ll>> delta(30, vector<ll>(29));
  for (int i = 0; i < 30; i++)
  {
    for (int j = 0; j < 29; j++)
    {
      ll absDelta = get_rand_range(0, D);
      ll pm = get_rand_range(0, 1);
      delta[i][j] = absDelta;
      if (!pm)
        delta[i][j] *= -1;
    }
  }

  if (M == 1)
  {
    for (int i = 0; i < 30; i++)
    {
      for (int j = 0; j < 29; j++)
      {
        h[i][j] = H[i][0] + delta[i][j];
        G[i * 30 + j].push_back({i * 30 + j + 1, h[i][j]});
        G[i * 30 + j + 1].push_back({i * 30 + j, h[i][j]});
      }
    }
  }
  else
  {
    for (int i = 0; i < 30; i++)
    {
      int x = get_rand_range(1, 28);
      for (int j = 0; j < x; j++)
      {
        h[i][j] = H[i][0] + delta[i][j];
        G[i * 30 + j].push_back({i * 30 + j + 1, h[i][j]});
        G[i * 30 + j + 1].push_back({i * 30 + j, h[i][j]});
      }
      for (int j = x; j < 29; j++)
      {
        h[i][j] = H[i][1] + delta[i][j];
        G[i * 30 + j].push_back({i * 30 + j + 1, h[i][j]});
        G[i * 30 + j + 1].push_back({i * 30 + j, h[i][j]});
      }
    }
  }

  // y方向の初期距離の決定
  vector<vector<ll>> V(30, vector<ll>(M));
  for (int i = 0; i < 30; i++)
  {
    for (int j = 0; j < M; j++)
    {
      V[i][j] = get_rand_range(1000 + D, 9000 - D);
    }
  }

  vector<vector<ll>> gamma(29, vector<ll>(30));
  for (int i = 0; i < 29; i++)
  {
    for (int j = 0; j < 30; j++)
    {
      ll absDelta = get_rand_range(0, D);
      ll pm = get_rand_range(0, 1);
      gamma[i][j] = absDelta;
      if (!pm)
        gamma[i][j] *= -1;
    }
  }

  if (M == 1)
  {
    for (int i = 0; i < 29; i++)
    {
      for (int j = 0; j < 30; j++)
      {
        v[i][j] = V[j][0] + gamma[i][j];
        G[i * 30 + j].push_back({(i + 1) * 30 + j, v[i][j]});
        G[(i + 1) * 30 + j].push_back({i * 30 + j, v[i][j]});
      }
    }
  }
  else
  {

    for (int j = 0; j < 30; j++)
    {
      int y = get_rand_range(1, 28);
      for (int i = 0; i < y; i++)
      {
        v[i][j] = V[j][0] + gamma[i][j];
        G[i * 30 + j].push_back({(i + 1) * 30 + j, v[i][j]});
        G[(i + 1) * 30 + j].push_back({i * 30 + j, v[i][j]});
      }
      for (int i = y; i < 29; i++)
      {
        v[i][j] = V[j][1] + gamma[i][j];
        G[i * 30 + j].push_back({(i + 1) * 30 + j, v[i][j]});
        G[(i + 1) * 30 + j].push_back({i * 30 + j, v[i][j]});
      }
    }
  }

  /*
  for (int i = 0; i < h.size(); i++)
  {
    for (int j = 0; j < h[i].size(); j++)
    {
      cerr << h[i][j] << " ";
    }
    cerr << endl;
  }
  for (int i = 0; i < v.size(); i++)
  {
    for (int j = 0; j < v[i].size(); j++)
    {
      cerr << v[i][j] << " ";
    }
    cerr << endl;
  }
  */
  return;
}

string dijkstra(Graph &G, int start, int end, ll &pathDist)
{
  vector<vector<int>> prev_y(30, vector<int>(30, -1));
  vector<vector<int>> prev_x(30, vector<int>(30, -1));

  vector<ll> dist(G.size(), INT_INF);
  // pair(その時点での最短経路，頂点番号)
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
  dist[start] = 0;
  que.push(make_pair(dist[start], start));
  while (!que.empty())
  {
    ll cost = que.top().first;
    ll idx = que.top().second;
    que.pop();
    if (dist[idx] < cost)
      continue;

    for (auto e : G[idx])
    {
      if (dist[e.to] <= cost + e.weight)
        continue;
      dist[e.to] = cost + e.weight;
      que.push(make_pair(dist[e.to], e.to));
      int y = idx / 30, x = idx % 30;
      int ny = e.to / 30, nx = e.to % 30;
      prev_y[ny][nx] = y;
      prev_x[ny][nx] = x;
    }
  }

  pathDist = dist[end];

  string ans;
  int ty = end / 30, tx = end % 30;
  int y = ty, x = tx;
  int sy = start / 30, sx = start % 30;
  // cerr << "sy: " << sy << "  sx: " << sx << endl;
  // cerr << "ty: " << ty << "  tx: " << tx << endl;
  while (x != -1 && y != -1)
  {
    int py = prev_y[y][x], px = prev_x[y][x];
    // cerr << "y: " << y << "  py: " << py << "  x: " << x << "  px: " << px << endl;
    if (py != -1 && y - py == 1)
    {
      ans += "D";
    }
    else if (py != -1 && y - py == -1)
    {
      ans += "U";
    }
    else if (px != -1 && x - px == 1)
    {
      ans += "R";
    }
    else if (px != -1 && x - px == -1)
    {
      ans += "L";
    }
    y = py, x = px;
  }
  // cerr << "ans: " << ans << endl;
  reverse(ans.begin(), ans.end());
  return ans;
}

void modifyDistance(Graph &G, vector<vector<ll>> &h, vector<vector<ll>> &v, vector<P> &svec, vector<P> &tvec, vector<ll> &pathvec, vector<ll> &distvec, vector<string> &ansvec, string ans, ll dist, ll pathLength, int sy, int sx, int ty, int tx)
{
  // diffがしきい値以下になるまで繰り返すやつをやる
  int loopCnt = 0;
  while (loopCnt < 5)
  {
    // vector<ll> bestChangeDist(ans.size());
    // Graph backUpGraph = G;
    ll changeQuant = ansvec.back().size(); // get_rand_range(0, ans.size()); // 変更する個数を決める
    // ll changeQuant = get_rand_range(5, ansvec.back().size());
    vector<ll> changeDist(ansvec.back().size());
    vector<bool> used(ansvec.back().size());
    int cnt = 0;
    vector<int> changeIdxs;
    while (cnt < changeQuant)
    {
      int idx = get_rand_range(0, ansvec.back().size() - 1);
      if (!used[idx])
      {
        used[idx] = true;
        changeIdxs.push_back(idx);
        cnt++;
      }
    }

    if (changeIdxs.size())
    {
      sort(changeIdxs.begin(), changeIdxs.end());

      // 間違った距離が最短経路として出力されてしまっている　基本的には増やさないといけない？
      ll distDiff = abs(distvec.back() - pathvec.back());

      if (distDiff <= 500)
        return;
      ll distDiffAve = distDiff / changeQuant;

      if (distvec.back() >= pathvec.back())
      {
        // 減らす
        int now = 0;
        int nowy = sy, nowx = sx;
        for (int i = 0; i < ansvec.back().size(); i++)
        {
          int nxty = nowy, nxtx = nowx;
          if (ansvec.back()[i] == 'U')
          {
            nxty--;
          }
          if (ansvec.back()[i] == 'D')
          {
            nxty++;
          }
          if (ansvec.back()[i] == 'R')
          {
            nxtx++;
          }
          if (ansvec.back()[i] == 'L')
          {
            nxtx--;
          }
          if (now < changeIdxs.size() && i == changeIdxs[now])
          {
            int nowIdx = nowy * 30 + nowx, nxtIdx = nxty * 30 + nxtx;
            ll nowDist;
            for (auto &e : G[nowIdx])
            {
              if (e.to == nxtIdx)
              {
                nowDist = e.weight;
              }
            }

            // nowDist = get_rand_range(max(1000LL, nowDist - 3 * distDiffAve), min(9000LL, nowDist + distDiffAve / 10);
            if (get_rand_range_real(0.0, 1.0) > 0.2)
            {
              nowDist -= (ll)get_rand_normal(distDiffAve + distDiffAve * 2 / 10, (double)distDiffAve / 3.);
              nowDist = max(1000LL, nowDist);
            }
            else
            {
              nowDist += (ll)get_rand_normal(distDiffAve / 5., (double)distDiffAve / 15.);
              nowDist = min(9000LL, nowDist);
            }
            // nowDist = max(1000LL, nowDist - distDiffAve * 4 / 5);
            for (auto &e : G[nowIdx])
            {
              if (e.to == nxtIdx)
              {
                e.weight = nowDist;
              }
            }
            for (auto &e : G[nxtIdx])
            {
              if (e.to == nowIdx)
              {
                e.weight = nowDist;
              }
            }
            now++;
          }
          nowy = nxty, nowx = nxtx;
        }
      }
      else
      {
        // 増やす
        int now = 0;
        int nowy = sy, nowx = sx;
        for (int i = 0; i < ansvec.back().size(); i++)
        {
          int nxty = nowy, nxtx = nowx;
          if (ansvec.back()[i] == 'U')
          {
            nxty--;
          }
          if (ansvec.back()[i] == 'D')
          {
            nxty++;
          }
          if (ansvec.back()[i] == 'R')
          {
            nxtx++;
          }
          if (ansvec.back()[i] == 'L')
          {
            nxtx--;
          }
          if (now < changeIdxs.size() && i == changeIdxs[now])
          {
            int nowIdx = nowy * 30 + nowx, nxtIdx = nxty * 30 + nxtx;
            ll nowDist;
            for (auto &e : G[nowIdx])
            {
              if (e.to == nxtIdx)
              {
                nowDist = e.weight;
              }
            }

            // nowDist = get_rand_range(max(1000LL, nowDist - distDiffAve / 10), min(9000LL, nowDist + distDiffAve * 3));
            // nowDist = min(9000LL, nowDist + distDiffAve * 3 / 2);
            if (get_rand_range_real(0.0, 1.0) > 0.2)
            {
              nowDist += (ll)get_rand_normal(distDiffAve + distDiffAve * 2 / 10, (double)distDiffAve / 3.);
              nowDist = min(9000LL, nowDist);
            }
            else
            {
              nowDist -= (ll)get_rand_normal(distDiffAve / 5., (double)distDiffAve / 15.);
              nowDist = max(1000LL, nowDist);
            }
            for (auto &e : G[nowIdx])
            {
              if (e.to == nxtIdx)
              {
                e.weight = nowDist;
              }
            }
            for (auto &e : G[nxtIdx])
            {
              if (e.to == nowIdx)
              {
                e.weight = nowDist;
              }
            }
            now++;
          }
          nowy = nxty, nowx = nxtx;
        }
      }
    }
    ll afterDist = 0;
    string afterAns = dijkstra(G, sy * 30 + sx, ty * 30 + tx, afterDist);
    // cerr << "after dist: " << afterDist << endl;
    // cerr << "after ans: " << afterAns << endl;
    ansvec.back() = afterAns;
    distvec.back() = afterDist;
    if (abs(afterDist - pathvec.back()) < 500)
      break;
    // どれだけルートが変わったかで評価をする？
  }
  return;
}

void modifyAllPath(Graph &G, vector<vector<ll>> &h, vector<vector<ll>> &v, vector<P> &svec, vector<P> &tvec, vector<ll> &pathvec, vector<ll> &distvec, vector<string> &ansvec)
{
  for (int i = 0; i < svec.size() - 1; i++)
  {
    ll changeQuant = ansvec[i].size(); // get_rand_range(0, ans.size()); // 変更する個数を決める
    vector<ll> changeDist(ansvec[i].size());
    vector<bool> used(ansvec[i].size());
    int cnt = 0;
    vector<int> changeIdxs;
    while (cnt < changeQuant)
    {
      int idx = get_rand_range(0, ansvec[i].size() - 1);
      if (!used[idx])
      {
        used[idx] = true;
        changeIdxs.push_back(idx);
        cnt++;
      }
    }

    if (changeIdxs.size())
    {
      sort(changeIdxs.begin(), changeIdxs.end());

      // 間違った距離が最短経路として出力されてしまっている　基本的には増やさないといけない？
      ll distDiff = abs(distvec[i] - pathvec[i]);

      if (distDiff <= 500)
        return;
      ll distDiffAve = distDiff / changeQuant;

      if (distvec[i] >= pathvec[i])
      {
        // 減らす
        int now = 0;
        int nowy = svec[i].first, nowx = svec[i].second;
        for (int j = 0; j < ansvec[i].size(); j++)
        {
          int nxty = nowy, nxtx = nowx;
          if (ansvec[i][j] == 'U')
          {
            nxty--;
          }
          if (ansvec[i][j] == 'D')
          {
            nxty++;
          }
          if (ansvec[i][j] == 'R')
          {
            nxtx++;
          }
          if (ansvec[i][j] == 'L')
          {
            nxtx--;
          }
          if (now < changeIdxs.size() && j == changeIdxs[now])
          {
            int nowIdx = nowy * 30 + nowx, nxtIdx = nxty * 30 + nxtx;
            ll nowDist;
            for (auto &e : G[nowIdx])
            {
              if (e.to == nxtIdx)
              {
                nowDist = e.weight;
              }
            }

            // nowDist = get_rand_range(max(1000LL, nowDist - 3 * distDiffAve), min(9000LL, nowDist + distDiffAve / 10));
            nowDist -= 3 * (ll)get_rand_normal(distDiffAve, (double)distDiffAve / 10.) / 2;
            nowDist = max(1000LL, nowDist);
            // nowDist = max(1000LL, nowDist - distDiffAve * 4 / 5);
            for (auto &e : G[nowIdx])
            {
              if (e.to == nxtIdx)
              {
                e.weight = nowDist;
              }
            }
            for (auto &e : G[nxtIdx])
            {
              if (e.to == nowIdx)
              {
                e.weight = nowDist;
              }
            }
            now++;
          }
          nowy = nxty, nowx = nxtx;
        }
      }
      else
      {
        // 増やす
        int now = 0;
        int nowy = svec[i].first, nowx = svec[i].second;
        for (int j = 0; j < ansvec[i].size(); j++)
        {
          int nxty = nowy, nxtx = nowx;
          if (ansvec[i][j] == 'U')
          {
            nxty--;
          }
          if (ansvec[i][j] == 'D')
          {
            nxty++;
          }
          if (ansvec[i][j] == 'R')
          {
            nxtx++;
          }
          if (ansvec[i][j] == 'L')
          {
            nxtx--;
          }
          if (now < changeIdxs.size() && j == changeIdxs[now])
          {
            int nowIdx = nowy * 30 + nowx, nxtIdx = nxty * 30 + nxtx;
            ll nowDist;
            for (auto &e : G[nowIdx])
            {
              if (e.to == nxtIdx)
              {
                nowDist = e.weight;
              }
            }

            // nowDist = get_rand_range(max(1000LL, nowDist - distDiffAve / 10), min(9000LL, nowDist + distDiffAve * 3));
            // nowDist = min(9000LL, nowDist + distDiffAve * 3 / 2);
            nowDist += 3 * (ll)get_rand_normal(distDiffAve, (double)distDiffAve / 10.) / 2;
            nowDist = min(9000LL, nowDist);
            for (auto &e : G[nowIdx])
            {
              if (e.to == nxtIdx)
              {
                e.weight = nowDist;
              }
            }
            for (auto &e : G[nxtIdx])
            {
              if (e.to == nowIdx)
              {
                e.weight = nowDist;
              }
            }
            now++;
          }
          nowy = nxty, nowx = nxtx;
        }
      }
    }
    ll afterDist = 0;
    string afterAns = dijkstra(G, svec[i].first * 30 + svec[i].second, tvec[i].first * 30 + tvec[i].second, afterDist);
    // どれだけルートが変わったかで評価をする？
    ansvec[i] = afterAns;
    distvec[i] = afterDist;
  }
  return;
}

void reGenInitGrid(Graph &G, vector<vector<ll>> &h, vector<vector<ll>> &v, vector<P> &svec, vector<P> &tvec, vector<ll> &pathvec, vector<ll> &distvec, vector<string> &ansvec)
{
  int n = pathvec.size();
  while (true)
  {
    bool ok = true;
    genInitGrid(G, h, v);
    for (int i = 0; i < n; i++)
    {
      ansvec[i] = dijkstra(G, svec[i].first * 30 + svec[i].second, tvec[i].first * 30 + tvec[i].second, distvec[i]);
      // cerr << "dist: " << distvec[i] << "  pathLength: " << pathvec[i] << endl;
      if (abs(distvec[i] - pathvec[i]) > 5000)
      {
        ok = false;
        break;
      }
    }
    if (ok)
      break;
  }
  // cerr << "ok. " << n << "th paths created." << endl;
  return;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Graph G(30 * 30);
  vector<vector<ll>> h(30, vector<ll>(29));
  vector<vector<ll>> v(29, vector<ll>(30));
  genInitGrid(G, h, v);
  long double sum = 0.0;
  int modifyCntr = 0;
  vector<P> svec, tvec;
  vector<ll> pathvec;
  vector<ll> distvec;
  vector<string> ansvec;
  for (int i = 0; i < 1000; i++)
  {
    // cerr << "/////////////////////////// query : " << i << " ///////////////////" << endl;
    int si, sj, ti, tj;
    cin >> si >> sj >> ti >> tj;
    svec.push_back({si, sj}), tvec.push_back({ti, tj});
    ll dist = 0;
    string ans = dijkstra(G, si * 30 + sj, ti * 30 + tj, dist);
    cout << ans << endl;
    distvec.push_back(dist);
    ansvec.push_back(ans);
    ll pathLength;
    cin >> pathLength;
    pathvec.push_back(pathLength);
    // cerr << "pathLength: " << pathLength << "  dist: " << dist << endl;
    /*
    if (i < 250 && i - modifyCntr > 50 && abs(pathLength - dist) > (-9 * i + 10000))
    {
      double chProb = (-0.9999 * i / 1000.0) + 1.0;
      if (chProb > get_rand_range_real(0.0, 1.0))
      {
        modifyAllDistance(G, i);
        modifyCntr = i;
        continue;
      }
    }
    */
    /*
    if (i % 500 == 0)
    {
      reGenInitGrid(G, h, v, svec, tvec, pathvec, distvec, ansvec);
      continue;
    }*/
    modifyDistance(G, h, v, svec, tvec, pathvec, distvec, ansvec, ans, dist, pathLength, si, sj, ti, tj);
    // if (i == 500)
    // modifyAllPath(G, h, v, svec, tvec, pathvec, distvec, ansvec);
  }
  return 0;
}
// 2021.05.25 0:51
