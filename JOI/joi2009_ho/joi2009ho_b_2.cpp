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
  ll d;
  cin >> d;
  int n, m;
  cin >> n >> m;
  vector<ll> dist(n);
  for (int i = 1; i < n; i++)
    cin >> dist[i];

  dist.push_back(d);
  sort(dist.begin(), dist.end());
  vector<ll> k(m);
  for (auto &it : k)
    cin >> it;

  ll sum = 0;
  for (int i = 0; i < m; i++)
  {
    int idx = lower_bound(dist.begin(), dist.end(), k[i]) - dist.begin();

    if (idx == 0)
      continue;
    sum += min(abs(k[i] - dist[idx]), abs(k[i] - dist[idx - 1]));
  }
  cout << sum << endl;
  return 0;
}
