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
  int N, M, R;
  cin >> N >> M >> R;
  vector<int> r(R);
  for (auto &it : r)
  {
    cin >> it;
    it--;
  }
  vector<vector<ll>> d(N, vector<ll>(N, INF / 2));
  for (int i = 0; i < M; i++)
  {
    int A, B, C;
    cin >> A >> B >> C;
    A--, B--;
    if (d[A][B] > C)
      d[A][B] = C, d[B][A] = C;
  }
  for (int i = 0; i < N; i++)
    d[i][i] = 0;
  for (int k = 0; k < N; k++)
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  vector<int> v(R);
  iota(v.begin(), v.end(), 0);
  ll ans = INF;
  do
  {
    ll tmp = 0;
    for (int i = 1; i < R; i++)
    {
      tmp += d[r[v[i]]][r[v[i - 1]]];
    }
    ans = min(tmp, ans);
  } while (next_permutation(v.begin(), v.end()));
  cout << ans << endl;
  return 0;
}

// next_permutationとワーシャルフロイド
