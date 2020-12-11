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

void check(vector<vector<int>> &a, int n, int l, int r)
{
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    int nxt = -1;
    if (a[l][0] == r)
    {
      nxt = a[l][1];
    }
    else if (a[l][1] == r)
    {
      nxt = a[l][0];
    }
    else
    {
      return;
    }
    ans.push_back(nxt);
    l = r;
    r = nxt;
  }
  for (auto &it : ans)
  {
    cout << it + 1 << " ";
  }
  cout << endl;
  exit(0);
}

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(2));
  for (int i = 0; i < n; i++)
  {
    cin >> a[i][0] >> a[i][1];
    a[i][0]--, a[i][1]--;
  }

  check(a, n, 0, a[0][0]);
  check(a, n, 0, a[0][1]);
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
