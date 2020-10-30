#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
// using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<pair<ll, ll>> wh(N);
  for (auto &it : wh)
  {
    cin >> it.first >> it.second;
    it.second = -it.second;
  }
  sort(wh.begin(), wh.end());
  vector<ll> dp(N + 1, INF);
  for (int i = 0; i < N; i++)
  {
    *lower_bound(dp.begin(), dp.end(), -wh[i].second) = -wh[i].second;
  }
  ll ans = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
  cout << ans << endl;
  return 0;
}

// x, yについて昇順にソートすると1 2, 1 3のようなときに長さが2であると判定されてしまう．これを防ぐためにはxが同じときはyは降順にソートする(yの方には-1をかけておく)->1 3, 1 2, 2 5, 2 4, 2 3, ...
// LISを求めるときのDPテーブルの動きを思い出す．
