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
  int n;
  cin >> n;
  string s;
  cin >> s;
  string rs(s.rbegin(), s.rend());
  for (int i = 0; i < n; i++)
  {
    if (rs[i] == '(')
      rs[i] = ')';
    else
      rs[i] = '(';
  }

  vector<int> pref(n + 1), suf(n + 1);
  vector<bool> okp(n + 1), oks(n + 1);
  okp[0] = oks[n] = true;
  for (int i = 0; i < n; i++)
  {
    pref[i + 1] = pref[i] + (s[i] == '(' ? 1 : -1);
    okp[i + 1] = okp[i] & (pref[i + 1] >= 0);
    suf[n - i - 1] = suf[n - i] + (rs[i] == '(' ? 1 : -1);
    oks[n - i - 1] = oks[n - i] & (suf[n - i - 1] >= 0);
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (!okp[i] || !oks[i + 1])
      continue;
    if (s[i] == '(')
    {
      if (pref[i] > 0 && pref[i] - 1 - suf[i + 1] == 0)
        ans++;
    }
    else
    {
      if (pref[i] + 1 - suf[i + 1] == 0)
        ans++;
    }
  }
  cout << ans << endl;
  return;
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
