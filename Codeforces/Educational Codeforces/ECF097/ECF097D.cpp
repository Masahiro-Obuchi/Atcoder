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

  vector<vector<int>> b(n + 10);
  b[0].push_back(1);
  int depth = 1;
  int ch_num = 0;
  for (int i = 1; i < n; i++)
  {
    if (b[depth].size() == 0)
    {
      b[depth].push_back(a[i]);
      ch_num = 1;
    }
    else
    {
      if (a[i] < a[i - 1])
      {
        if (ch_num == b[depth - 1].size())
        {
          depth++;
          b[depth].push_back(a[i]);
          ch_num = 1;
        }
        else
        {
          ch_num++;
          b[depth].push_back(a[i]);
        }
      }
      else
      {
        b[depth].push_back(a[i]);
      }
    }
  }
  cout << depth << endl;
  return;
}

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
