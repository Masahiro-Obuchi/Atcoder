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

bool check(ll x, int n, int m, ll k, vector<ll> &a)
{
  int curBox = 1;
  ll cnt = 0;
  for (int i = x; i < n; i++)
  {
    if (cnt + a[i] <= k)
    {
      cnt += a[i];
    }
    else
    {
      curBox++;
      cnt = a[i];
    }
  }

  if (curBox > m)
  {
    return false;
  }
  else
    return true;
}

void solve()
{
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  for (auto &it : a)
    cin >> it;

  ll left = -1, right = n - 1;
  while (left + 1 < right)
  {
    ll mid = (left + right) / 2;
    if (check(mid, n, m, k, a))
      right = mid;
    else
      left = mid;
  }
  cout << n - right << endl;
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

// Let's do binary search on the answer.
