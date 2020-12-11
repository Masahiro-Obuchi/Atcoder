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
  int res = 0;
  vector<char> ch = {'R', 'G', 'B'};
  for (int i = 1; i < n; i++)
  {
    if (i == n - 1)
    {
      if (s[i] == s[i - 1])
      {
        res++;
        if (s[i - 1] == ch[0])
        {
          s[i] = ch[1];
        }
        else if (s[i - 1] == ch[1])
        {
          s[i] = ch[2];
        }
        else
        {
          s[i] = ch[0];
        }
      }
      continue;
    }
    if (s[i] == s[i - 1])
    {
      if (s[i - 1] == s[i + 1])
      {
        res++;
        if (s[i - 1] == ch[0])
        {
          s[i] = ch[1];
        }
        else if (s[i - 1] == ch[1])
        {
          s[i] = ch[2];
        }
        else
        {
          s[i] = ch[0];
        }
      }
      else
      {
        bool usedR = false, usedG = false, usedB = false;
        for (int j = i - 1; j <= i + 1; j++)
        {
          if (s[j] == ch[0])
            usedR = true;
          if (s[j] == ch[1])
            usedG = true;
          if (s[j] == ch[2])
            usedB = true;
        }
        int idx = -1;
        if (!usedR)
          idx = 0;
        else if (!usedG)
          idx = 1;
        else
          idx = 2;
        res++;
        s[i] = ch[idx];
      }
    }
  }
  cout << res << endl;
  cout << s << endl;
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
