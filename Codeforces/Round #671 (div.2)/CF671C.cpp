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
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto &it : a)
    cin >> it;
  ll diff_sum = 0;
  bool all_zero = true;
  bool existx = false;
  for (int i = 0; i < n; i++)
  {
    ll tmp = x - a[i];
    if (tmp != 0)
    {
      all_zero = false;
    }
    else
      existx = true;
    diff_sum += tmp;
  }
  if (all_zero)
  {
    cout << 0 << endl;
    return;
  }

  if (diff_sum == 0 || existx)
  {
    cout << 1 << endl;
    return;
  }

  cout << 2 << endl;
  return;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    solve();
  }
  return 0;
}
