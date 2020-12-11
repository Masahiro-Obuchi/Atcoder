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
  vector<char> ch = {'R', 'G', 'B'};
  vector<int> res(6, 0);
  vector<string> t(6, s);
  // RGB
  for (int i = 0; i < n; i++)
  {
    if (i % 3 == 0)
    {
      if (t[0][i] != ch[0])
      {
        t[0][i] = ch[0];
        res[0]++;
      }
    }
    else if (i % 3 == 1)
    {
      if (t[0][i] != ch[1])
      {
        t[0][i] = ch[1];
        res[0]++;
      }
    }
    else
    {
      if (t[0][i] != ch[2])
      {
        t[0][i] = ch[2];
        res[0]++;
      }
    }
  }
  // RBG
  for (int i = 0; i < n; i++)
  {
    if (i % 3 == 0)
    {
      if (t[1][i] != ch[0])
      {
        t[1][i] = ch[0];
        res[1]++;
      }
    }
    else if (i % 3 == 1)
    {
      if (t[1][i] != ch[2])
      {
        t[1][i] = ch[2];
        res[1]++;
      }
    }
    else
    {
      if (t[1][i] != ch[1])
      {
        t[1][i] = ch[1];
        res[1]++;
      }
    }
  }
  // GBR
  for (int i = 0; i < n; i++)
  {
    if (i % 3 == 0)
    {
      if (t[2][i] != ch[1])
      {
        t[2][i] = ch[1];
        res[2]++;
      }
    }
    else if (i % 3 == 1)
    {
      if (t[2][i] != ch[2])
      {
        t[2][i] = ch[2];
        res[2]++;
      }
    }
    else
    {
      if (t[2][i] != ch[0])
      {
        t[2][i] = ch[0];
        res[2]++;
      }
    }
  }
  // GRB
  for (int i = 0; i < n; i++)
  {
    if (i % 3 == 0)
    {
      if (t[3][i] != ch[1])
      {
        t[3][i] = ch[1];
        res[3]++;
      }
    }
    else if (i % 3 == 1)
    {
      if (t[3][i] != ch[0])
      {
        t[3][i] = ch[0];
        res[3]++;
      }
    }
    else
    {
      if (t[3][i] != ch[2])
      {
        t[3][i] = ch[2];
        res[3]++;
      }
    }
  }
  // BRG
  for (int i = 0; i < n; i++)
  {
    if (i % 3 == 0)
    {
      if (t[4][i] != ch[2])
      {
        t[4][i] = ch[2];
        res[4]++;
      }
    }
    else if (i % 3 == 1)
    {
      if (t[4][i] != ch[0])
      {
        t[4][i] = ch[0];
        res[4]++;
      }
    }
    else
    {
      if (t[4][i] != ch[1])
      {
        t[4][i] = ch[1];
        res[4]++;
      }
    }
  }
  //BGR
  for (int i = 0; i < n; i++)
  {
    if (i % 3 == 0)
    {
      if (t[5][i] != ch[2])
      {
        t[5][i] = ch[2];
        res[5]++;
      }
    }
    else if (i % 3 == 1)
    {
      if (t[5][i] != ch[1])
      {
        t[5][i] = ch[1];
        res[5]++;
      }
    }
    else
    {
      if (t[5][i] != ch[0])
      {
        t[5][i] = ch[0];
        res[5]++;
      }
    }
  }
  int idx = -1;
  int ans = INT_INF;
  for (int i = 0; i < 6; i++)
  {
    if (res[i] < ans)
    {
      ans = res[i];
      idx = i;
    }
  }
  cout << ans << endl;
  cout << t[idx] << endl;
  return;
}
// 最初を何の文字にするかで3通り

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
