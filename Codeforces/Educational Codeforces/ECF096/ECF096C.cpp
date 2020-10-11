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
  cout << 2 << endl;
  if (n == 2)
  {
    cout << 1 << " " << 2 << endl;
  }
  else
  {
    if (n == 3)
    {
      cout << 1 << " " << 3 << endl;
      cout << 2 << " " << 2 << endl;
      return;
    }

    cout << n - 2 << " " << n << endl;
    cout << n - 1 << " " << n - 1 << endl;
    int now = n - 1;
    for (int i = 0; i < n - 3; i++)
    {
      cout << now - 2 << " " << now << endl;
      now--;
    }
  }
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
