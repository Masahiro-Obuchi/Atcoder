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
  bool can = false;
  int three, five, seven;
  for (int i = 0; 3 * i <= n; i++)
  {
    for (int j = 0; 5 * j <= n; j++)
    {
      int seven_k = n - 3 * i - 5 * j;
      // cerr << "seven_k: " << seven_k << endl;
      if (seven_k % 7 == 0)
      {
        seven_k /= 7;
        if (seven_k >= 0)
        {
          can = true;
          three = i, five = j, seven = seven_k;
          break;
        }
      }
      else
      {
        continue;
      }
    }
  }

  if (can)
  {
    cout << three << " " << five << " " << seven << endl;
  }
  else
    cout << -1 << endl;
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
