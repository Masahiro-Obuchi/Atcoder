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

// ax + b = 0
pair<int, int> solve1(int a, int b)
{
  if (b == 0)
    return {0, 0};
  if (b > 0)
    return {0, 1};
  return {1, 0};
}

// ax^2 + bx + c = 0
pair<int, int> solve2(int a, int b, int c)
{
  if (c == 0)
    return solve1(a, b);
  int D = b * b - 4 * a * c;
  if (D < 0)
    return {0, 0};
  if (c < 0)
    return {1, 1};
  if (b > 0)
    return {0, 2};

  return {2, 0};
}

// ax^3 + bx^2 + cx + d = 0
pair<int, int> solve3(ll a, ll b, ll c, ll d)
{
  if (a < 0)
    return solve3(-a, -b, -c, -d);
  if (d == 0)
    return solve2(a, b, c);

  ll D = b * b * c * c - 4 * a * c * c * c - 4 * b * b * b * d - 27 * a * a * d * d + 18 * a * b * c * d;
  int DD = b * b - 3 * a * c;

  bool minimal_x_plus = (b < 0 || DD > b * b), maximal_x_minus = (b > 0 || b * b < DD);

  if (D >= 0)
  {
    if (DD == 0)
    {
      if (b > 0)
        return {0, 3};
      else
        return {3, 0};
    }
    if (d > 0)
    {
      if (!minimal_x_plus)
        return {0, 3};
      else
        return {2, 1};
    }
    else
    {
      if (!maximal_x_minus)
        return {3, 0};
      else
        return {1, 2};
    }
  }
  else
  {
    if (d > 0)
    {
      return {0, 1};
    }
    return {1, 0};
  }
}

void solve()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  pair<int, int> ans = solve3(a, b, c, d);
  cout << ans.first << " " << ans.second << endl;
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
