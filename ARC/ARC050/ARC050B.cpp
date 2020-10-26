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
bool check(ll mid, ll R, ll B, ll x, ll y)
{
  ll red = (R - mid) / (x - 1);
  ll blue = (B - mid) / (y - 1);
  if (red + blue >= mid)
    return true;
  return false;
}
// 作れる赤い花束の個数をs1, 青い花束の個数をs2とするとs1 + s2 >= k, x*s1 + s2 <= R, s1 + y*s2 <= B, 0 <= s1,s2. 条件2の両辺にs1を足して条件1を用いて整理するとs1 <= (R - k)/(x - 1)となる．s2も同様．

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll R, B;
  ll x, y;
  cin >> R >> B >> x >> y;
  ll left = 0, right = min(R, B) + 1;
  while (left + 1 < right)
  {
    ll mid = (left + right) / 2;
    if (check(mid, R, B, x, y))
      left = mid;
    else
      right = mid;
  }
  cout << left << endl;
  return 0;
}
