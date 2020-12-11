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
  const int N = 1010;
  vector<vector<int>> a(n, vector<int>(n));
  vector<int> cnt(N + 1);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
      cnt[a[i][j]]++;
    }
  }

  vector<pair<int, P>> cells;
  for (int i = 0; i < (n + 1) / 2; i++)
  {
    for (int j = 0; j < (n + 1) / 2; j++)
    {
      if (i != n - i - 1 && j != n - j - 1)
        cells.push_back({4, {i, j}});
      else if ((i != n - i - 1) ^ (j != n - j - 1))
        cells.push_back({2, {i, j}});
      else
        cells.push_back({1, {i, j}});
    }
  }

  for (auto cur : {4, 2, 1})
  {
    int lst = 1;
    for (auto it : cells)
    {
      if (it.first != cur)
        continue;
      int i = it.second.first;
      int j = it.second.second;
      while (lst < N && cnt[lst] < cur)
      {
        lst++;
      }
      if (lst == N)
      {
        cout << "NO" << endl;
        return;
      }
      a[i][j] = a[n - i - 1][j] = a[i][n - j - 1] = a[n - i - 1][n - j - 1] = lst;
      cnt[lst] -= cur;
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << a[i][j] << " ";
    }
    cout << endl;
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
