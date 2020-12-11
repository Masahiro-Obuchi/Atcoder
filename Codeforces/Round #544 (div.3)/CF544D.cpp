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

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void solve()
{
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  ll zero = 0; // d = 0の場合に注意
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
    if (b[i] == 0)
      zero++;
  }

  ll ans = 0;
  map<pair<ll, ll>, ll> cnt;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == 0 && b[i] == 0)
    {
      ans++;
    }
    else if ((a[i] == 0 && b[i] != 0) || (a[i] != 0 && b[i] == 0))
      continue;
    else
    {
      ll g = gcd(a[i], b[i]);
      // cerr << "g: " << g << endl;
      ll ga = a[i] / g, gb = b[i] / g;
      cnt[{ga, gb}]++;
    }
  }

  ll res = 0;
  for (auto itr = cnt.begin(); itr != cnt.end(); itr++)
  {
    // cerr << itr->first.first << "/" << itr->first.second << "  " << itr->second << endl;
    res = max(res, itr->second);
  }
  cout << max(zero, res + ans) << endl;
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
