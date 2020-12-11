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

ll powll(ll a, ll n)
{
  ll res = 1;
  while (n > 0)
  {
    res *= a;
    n--;
  }
  return res;
}

void solve()
{
  ll n, k;
  cin >> n >> k;

  if (n < k)
  {
    cout << "NO" << endl;
    return;
  }

  vector<ll> ans(k, 1LL);
  if (n % 2 == 0)
  {
    ll diff = n - k;
    int now = k - 1;
    while (diff > 0 && now >= 0)
    {
      int idx = 1;
      for (int i = 1; i < 50; i++)
      {
        if (powll(2, i) - 1 > diff)
        {
          idx = i - 1;
          break;
        }
      }
      ans[now] = powll(2, idx);
      diff -= ans[now] - 1;
      if (diff == 0)
        break;
      now--;
      if (now < 0)
      {
        cout << "NO" << endl;
        return;
      }
    }
    if (diff == 0)
    {
      cout << "YES" << endl;
      for (auto it : ans)
        cout << it << " ";
    }
    else
      cout << "NO" << endl;
  }
  else
  {
    ll diff = n - k;
    int now = k - 1;
    while (diff > 0 && now >= 1)
    {
      int idx = 1;
      for (int i = 1; i < 50; i++)
      {
        if (powll(2, i) - 1 > diff)
        {
          idx = i - 1;
          break;
        }
      }
      ans[now] = powll(2, idx);
      diff -= ans[now] - 1;
      if (diff == 0)
        break;
      now--;
      if (now < 1)
      {
        cout << "NO" << endl;
        return;
      }
    }
    if (diff == 0)
    {
      cout << "YES" << endl;
      for (auto it : ans)
        cout << it << " ";
    }
    else
      cout << "NO" << endl;
  }
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
