#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
// using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

void solve()
{
  ll p, f;
  cin >> p >> f;
  ll cnts, cntw;
  cin >> cnts >> cntw;
  ll s, w;
  cin >> s >> w;
  ll ans = 0;
  ll cnt = 0;
  for (int i = 0; i <= cnts; i++)
  {
    ll cp = p, cf = f;
    ll ccnts = cnts, ccntw = cntw;
    ll tmp = 0;
    if (s * i > p)
      continue;
    cp -= s * i;
    ccnts -= i;
    tmp += i;
    ll minus = min(ccntw, cp / w);
    tmp += minus;
    ccntw -= minus;
    if (s <= w)
    {
      minus = min(ccnts, cf / s);
      tmp += minus;
      cf -= s * minus;
      tmp += min(ccntw, cf / w);
    }
    else
    {
      minus = min(ccntw, cf / w);
      tmp += minus;
      cf -= w * minus;
      tmp += min(ccnts, cf / s);
    }
    if (tmp >= ans)
      cnt = i;
    ans = max(ans, tmp);
  }
  cout << ans << endl;
  // cerr << "cnt: " << cnt << endl;
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
