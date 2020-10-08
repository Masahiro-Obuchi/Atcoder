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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, x, m;
  cin >> n >> x >> m;
  vector<int> id(m, -1);
  vector<int> a;
  int len = 0;
  ll tot = 0;
  while (id[x] == -1)
  {
    a.push_back(x);
    id[x] = len;
    len++;
    tot += x;
    x = (x * x) % m;
  }
  int c = len - id[x];
  ll s = 0;
  for (int i = id[x]; i < len; i++)
    s += a[i];

  ll ans = 0;
  if (n <= len)
  {
    for (int i = 0; i < n; i++)
      ans += a[i];
  }
  else
  {
    ans += tot;
    n -= len;
    ans += s * (n / c);
    n %= c;
    for (int i = 0; i < n; i++)
    {
      ans += a[id[x] + i]; // 周期の始まりからi個．a[id[x]]には周期の始まりとなるxの値が入っている．
    }
  }
  cout << ans << endl;
  return 0;
}
