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
  int a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  int n = s.size();
  vector<pair<char, int>> cnts;
  cnts.push_back({s[0], 1});
  for (int i = 1; i < n; i++)
  {
    if (s[i] == s[i - 1])
      cnts.back().second++;
    else
    {
      cnts.push_back({s[i], 1});
    }
  }

  ll ans = 0;
  for (int i = 0; i < cnts.size(); i++)
  {
    if (i + 2 < cnts.size() && cnts[i].first == '1' && cnts[i + 1].first == '0' && cnts[i + 2].first == '1')
    {
      if (2 * a >= a + b * cnts[i + 1].second)
      {
        cnts[i + 1].first = '1';
        // cerr << "i: " << i << "add: " << b * cnts[i + 1].second << endl;
        ans += b * cnts[i + 1].second;
      }
    }
  }

  for (int i = 1; i < cnts.size(); i++)
  {
    if (cnts[i - 1].first == '1' && cnts[i].first == '1')
    {
      cnts[i - 1].first = '2';
    }
  }
  for (int i = 0; i < cnts.size(); i++)
  {
    if (cnts[i].first == '1')
      ans += a;
  }
  cout << ans << endl;
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
