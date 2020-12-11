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
  map<char, int> mp;
  for (int i = 0; i < n; i++)
    mp[s[i]]++;

  int less = 0;
  for (auto itr = mp.begin(); itr != mp.end(); itr++)
  {
    if (itr->second < n / 3)
      less++;
  }
  less += 3 - mp.size();

  if (less == 0)
  {
    cout << s << endl;
    return;
  }

  if (less == 1)
  {
    if (mp['0'] < n / 3)
    {
      for (int i = 0; i < n; i++)
      {
        if (s[i] == '1' || s[i] == '2')
        {
          if (mp[s[i]] > n / 3)
          {
            mp[s[i]]--;
            s[i] = '0';
          }
        }
      }
    }
    else if (mp['1'] < n / 3)
    {
      for (int i = 0; i < n; i++)
      {
        if (s[i] == '2' && mp[s[i]] > n / 3)
        {
          mp[s[i]]--;
          s[i] = '1';
        }
      }
      for (int i = n - 1; i >= 0; i--)
      {
        if (s[i] == '0' && mp[s[i]] > n / 3)
        {
          mp[s[i]]--;
          s[i] = '1';
        }
      }
    }
    else
    {
      for (int i = n - 1; i >= 0; i--)
      {
        if (s[i] == '0' || s[i] == '1')
        {
          if (mp[s[i]] > n / 3)
          {
            mp[s[i]]--;
            s[i] = '2';
          }
        }
      }
    }
  }
  else if (less == 2)
  {
    if (mp['0'] < n / 3 && mp['1'] < n / 3)
    {
      for (int i = 0; i < n; i++)
      {
        if (s[i] == '2' && mp['0'] < n / 3)
        {
          mp['0']++;
          s[i] = '0';
        }
        else
        {
          if (s[i] == '2' && mp['1'] < n / 3)
          {
            mp['1']++;
            s[i] = '1';
          }
        }
      }
    }
    else if (mp['1'] < n / 3 && mp['2'] < n / 3)
    {
      for (int i = n - 1; i >= 0; i--)
      {
        if (s[i] == '0' && mp['2'] < n / 3)
        {
          mp['2']++;
          s[i] = '2';
        }
        else
        {
          if (s[i] == '0' && mp['1'] < n / 3)
          {
            mp['1']++;
            s[i] = '1';
          }
        }
      }
    }
    else
    {
      for (int i = 0; i < n; i++)
      {
        if (s[i] == '1' && mp['0'] < n / 3)
        {
          mp['0']++;
          s[i] = '0';
        }
      }
      for (int i = n - 1; i >= 0; i--)
      {
        if (s[i] == '1' && mp['2'] < n / 3)
        {
          mp['2']++;
          s[i] = '2';
        }
      }
    }
  }
  cout << s << endl;
  return;
}
// もっと処理をまとめられるかも

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
