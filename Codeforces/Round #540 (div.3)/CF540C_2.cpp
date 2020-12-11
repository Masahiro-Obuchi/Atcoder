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

int rev(int i, int n)
{
  return n - i - 1;
}

void put(vector<vector<int>> &a, vector<pair<int, int>> pos, priority_queue<P> &q)
{
  auto t(q.top());
  q.pop();
  if (t.first < pos.size())
  {
    cout << "NO" << endl;
    exit(0);
  }
  for (auto [i, j] : pos)
  {
    a[i][j] = t.second;
  }
  t.first -= pos.size();
  q.push(t);
}

void solve()
{
  int n;
  cin >> n;

  map<int, int> cnts;
  for (int i = 0; i < n * n; i++)
  {
    int val;
    cin >> val;
    cnts[val]++;
  }

  priority_queue<P> q;
  for (auto [key, value] : cnts)
  {
    q.push({value, key});
  }

  vector<vector<int>> a(n, vector<int>(n));
  int m = n / 2;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < m; j++)
    {
      put(a, {{i, j}, {i, rev(j, n)}, {rev(i, n), j}, {rev(i, n), rev(j, n)}}, q);
    }
  }

  if (n % 2 != 0)
  {
    for (int i = 0; i < m; i++)
    {
      put(a, {{i, m}, {rev(i, n), m}}, q);
      put(a, {{m, i}, {m, rev(i, n)}}, q);
    }
    put(a, {{m, m}}, q);
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
