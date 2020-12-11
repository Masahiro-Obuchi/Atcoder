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

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (auto &it : a)
    cin >> it;
  sort(a.begin(), a.end(), greater<int>());

  for (int i = 1; i <= n; i++)
  {
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
      sum += max(0, a[j] - j / i);
    }
    if (sum >= m)
    {
      cout << i << endl;
      return;
    }
  }
  cout << -1 << endl;
  return;
}
// k日目で払い終わると考えた時，最適な飲み方は大きい方からk個割り当て，また大きい方からk個割り当て(-1される)，また大きい方からk個割り当て... のようにする　sigma(i=1)^n max(0, ai - (i - 1)/k) となる

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  t = 1;
  for (int i = 0; i < t; i++)
  {
    solve();
  }
  return 0;
}
