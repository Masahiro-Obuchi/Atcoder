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
  int n, k;
  cin >> n >> k;
  string t;
  cin >> t;
  string ans;
  string rep;
  string head;
  int idx = -1;
  for (int i = 1; i < n; i++)
  {
    int sz = n - i;
    string tmp = t.substr(i, sz);
    string tmp2 = t.substr(0, sz);
    if (tmp == tmp2)
    {
      idx = i;
      rep = t.substr(sz, n - sz);
      break;
    }
  }
  if (idx == -1)
  {
    for (int i = 0; i < k; i++)
      ans += t;
  }
  else
  {
    ans += t;
    for (int i = 0; i < k - 1; i++)
      ans += rep;
  }
  cout << ans << endl;
}

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
