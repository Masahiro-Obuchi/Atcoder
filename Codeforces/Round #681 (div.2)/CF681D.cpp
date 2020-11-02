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
  vector<ll> a(n);
  for (auto &it : a)
    cin >> it;
  if (n <= 2)
  {
    cout << "YES" << endl;
    return;
  }
  int idx = -1;
  for (int i = 1; i < n; i++)
  {
    if (a[i] > a[i - 1])
    {
      idx = i;
      break;
    }
  }
  if (idx == -1)
  {
    cout << "YES" << endl;
    return;
  }
  else
  {
    vector<ll> b = a;
    ll mi = b[idx - 1];
    b[idx] -= mi;
    for (int i = idx + 1; i < n; i++)
    {
      if (b[i] < b[i - 1])
      {
        cout << "NO" << endl;
        return;
      }
      else
      {
        ll diff = b[i] - b[i - 1];
        mi = min(mi, diff);
        b[i] -= mi;
      }
    }
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
  return;
}
// 左側から考える．谷となるidxの次のidxから貪欲に左の数に寄せていけばよい

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
