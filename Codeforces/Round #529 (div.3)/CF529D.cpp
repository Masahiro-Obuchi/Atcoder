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
  vector<P> ab(n);
  for (int i = 0; i < n; i++)
  {
    cin >> ab[i].first >> ab[i].second;
    ab[i].first--, ab[i].second--;
  }

  Graph G1(n);
  vector<int> in1(n, 0);

  int ng = -1;
  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      int a, b;
      a = ab[i].first, b = ab[i].second;
      G1[i].push_back(a);
      in1[a]++;
      G1[i].push_back(b);
      in1[b]++;
      ng = b;
    }
    else
    {
      int a, b;
      a = ab[i].first, b = ab[i].second;
      if (a != 0 && a != ng)
      {
        G1[i].push_back(a);
        in1[a]++;
      }
      if (b != 0 && b != ng)
      {
        G1[i].push_back(b);
        in1[b]++;
      }
    }
  }

  queue<int> que1;
  for (int i = 0; i < n; i++)
    if (in1[i] == 0)
      que1.push(i);

  vector<int> ans1;
  while (!que1.empty())
  {
    int v = que1.front();
    que1.pop();
    ans1.push_back(v);
    for (auto u : G1[v])
    {
      in1[u]--;
      if (in1[u] == 0)
        que1.push(u);
    }
  }

  Graph G2(n);
  vector<int> in2(n, 0);

  ng = -1;
  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      int a, b;
      a = ab[i].first, b = ab[i].second;
      G2[i].push_back(a);
      in2[a]++;
      G2[i].push_back(b);
      in2[b]++;
      ng = a;
    }
    else
    {
      int a, b;
      a = ab[i].first, b = ab[i].second;
      if (a != 0 && a != ng)
      {
        G2[i].push_back(a);
        in2[a]++;
      }
      if (b != 0 && b != ng)
      {
        G2[i].push_back(b);
        in2[b]++;
      }
    }
  }

  queue<int> que2;
  for (int i = 0; i < n; i++)
    if (in2[i] == 0)
      que2.push(i);

  vector<int> ans2;
  while (!que2.empty())
  {
    int v = que2.front();
    que2.pop();
    ans2.push_back(v);
    for (auto u : G2[v])
    {
      in2[u]--;
      if (in2[u] == 0)
        que2.push(u);
    }
  }

  if (ans1.size() == n)
  {
    for (auto it : ans1)
      cout << it + 1 << " ";
    cout << endl;
  }
  else
  {
    for (auto it : ans2)
      cout << it + 1 << " ";
    cout << endl;
  }
  return;
}
//　トポロジカルソート　閉路が出来ないように辺の張り方気を付ける

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
