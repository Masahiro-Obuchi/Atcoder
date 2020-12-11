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
  vector<int> a(n);
  for (auto &it : a)
    cin >> it;

  vector<int> evenSum(n + 1), oddSum(n + 1);
  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
    {
      evenSum[i + 1] = evenSum[i] + a[i];
      oddSum[i + 1] = oddSum[i];
    }
    else
    {
      oddSum[i + 1] = oddSum[i] + a[i];
      evenSum[i + 1] = evenSum[i];
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int e = evenSum[i] - evenSum[0] + oddSum[n] - oddSum[i + 1];
    int o = oddSum[i] - oddSum[0] + evenSum[n] - evenSum[i + 1];
    // 偶奇が変わるから
    if (e == o)
      ans++;
  }
  cout << ans << endl;
  return;
}
// 偶奇の累積和

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
