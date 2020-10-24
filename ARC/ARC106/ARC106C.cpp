#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
/*
struct Edge
{
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
*/
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  if (N == 1 && M == 0)
  {
    cout << 1 << " " << 2 << endl;
    return 0;
  }
  if (M < 0 || M == N || M == N - 1)
  {
    cout << -1 << endl;
    return 0;
  }
  vector<pair<ll, ll>> res;
  if (M == 0)
  {
    ll cur = 1;
    for (int i = 0; i < N; i++)
    {
      res.push_back({cur, cur + 1});
      cur += 2;
    }
  }
  else
  {
    ll cur = 2;
    for (int i = 0; i < M + 1; i++)
    {
      res.push_back({cur, cur + 1});
      cur += 2;
    }
    res.push_back({1, cur});
    cur += 2;
    for (int i = M + 2; i < N; i++)
    {
      res.push_back({cur, cur + 1});
      cur += 2;
    }
  }
  for (auto &it : res)
  {
    cout << it.first << " " << it.second << endl;
  }
  return 0;
}
