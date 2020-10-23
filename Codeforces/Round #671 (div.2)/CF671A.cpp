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
  string s;
  cin >> s;
  bool odd = false, even = false;
  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
    { // odd
      odd |= ((s[i] - '0') % 2 == 1);
    }
    else
    { // even
      even |= ((s[i] - '0') % 2 == 0);
    }
  }
  if (n % 2 == 1)
  {
    cout << (odd ? 1 : 2) << endl;
  }
  else
  {
    cout << (even ? 2 : 1) << endl;
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
