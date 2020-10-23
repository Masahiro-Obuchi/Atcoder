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
  sort(a.begin(), a.end(), greater<ll>());
  vector<ll> ans(n);
  int cnt = 0;
  if (n % 2 == 0)
  {
    for (int i = 0; i < n / 2; i++)
    {
      ans[n - 1 - (i * 2)] = a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n / 2; i++)
    {
      ans[i * 2] = a[i];
    }
    for (int i = 1; i < n - 1; i++)
    {
      if (ans[i - 1] > ans[i] && ans[i] < ans[i + 1])
        cnt++;
    }
    cout << cnt << endl;
    for (auto it : ans)
      cout << it << " ";
    cout << endl;
  }
  else
  {
    for (int i = 0; i <= n / 2; i++)
    {
      ans[n - 1 - (i * 2)] = a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n / 2; i++)
    {
      ans[1 + i * 2] = a[i];
    }
    for (int i = 1; i < n - 1; i++)
    {
      if (ans[i - 1] > ans[i] && ans[i] < ans[i + 1])
        cnt++;
    }
    cout << cnt << endl;
    for (auto it : ans)
      cout << it << " ";
    cout << endl;
  }
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
