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
  string s1, s2;
  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
    {
      s1 += "1";
      s2 += "0";
    }
    else
    {
      s1 += "0";
      s2 += "1";
    }
  }

  int cnt1 = 0, cnt2 = 0;
  int right = 0;
  for (int left = 0; left < n; left++)
  {
    bool ope = false;
    while (right < n && s[right] != s1[right])
    {
      ope = true;
      right++;
    }
    if (ope)
      cnt1++;
    if (left == right)
      right++;
  }

  right = 0;
  for (int left = 0; left < n; left++)
  {
    bool ope = false;
    while (right < n && s[right] != s2[right])
    {
      ope = true;
      right++;
    }
    if (ope)
      cnt2++;
    if (left == right)
      right++;
  }
  cout << min(cnt1, cnt2) << endl;
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
