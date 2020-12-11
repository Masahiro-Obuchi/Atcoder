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
  ll n, k, s;
  cin >> n >> k >> s;
  if (s > k * (n - 1) || k > s) // 操作回数がsを超えていたら必ず移動距離はsを超えてしまう
  {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  ll now = 1;
  int rem = k;
  for (int i = 0; i < k; i++)
  {
    ll dist = min(n - 1, s - rem + 1);
    if (now - dist > 0)
    {
      now -= dist;
      s -= dist;
      rem--;
      cout << now << " ";
    }
    else
    {
      now += dist;
      s -= dist;
      rem--;
      cout << now << " ";
    }
  }
  cout << endl;
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
