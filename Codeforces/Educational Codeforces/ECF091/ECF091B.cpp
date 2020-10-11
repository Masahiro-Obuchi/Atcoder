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

void solve()
{
  string s;
  cin >> s;
  int n = s.size();
  string ans;
  int R = 0, P = 0, S = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == 'R')
      P++;
    else if (s[i] == 'P')
      S++;
    else
      R++;
  }
  if (R >= S && R >= P)
  {
    for (int i = 0; i < n; i++)
      ans += "R";
  }
  else if (S >= R && S >= P)
  {
    for (int i = 0; i < n; i++)
      ans += "S";
  }
  else if (P >= R && P >= S)
  {
    for (int i = 0; i < n; i++)
      ans += "P";
  }
  cout << ans << endl;
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
