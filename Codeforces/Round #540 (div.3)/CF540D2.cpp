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

bool check(int x, int n, int m, vector<int> &a)
{
  ll sum = 0;
  for (int j = 0; j < n; j++)
  {
    sum += max(0, a[j] - j / x);
  }
  return sum >= m;
}

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (auto &it : a)
    cin >> it;
  sort(a.begin(), a.end(), greater<int>());

  int left = 1, right = n;
  while (left + 1 < right)
  {
    int mid = (left + right) / 2;
    if (check(mid, n, m, a))
      right = mid;
    else
      left = mid;
  }

  if (check(left, n, m, a))
    cout << left << endl;
  else if (check(right, n, m, a))
    cout << right << endl;
  else
    cout << -1 << endl;
  return;
}
// 書けるページ数に単調性がある　-> 二分探索が使える

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
