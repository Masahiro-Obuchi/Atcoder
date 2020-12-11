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

ll findNumOfDigits(ll n)
{
  ll res = 0;
  while (n > 0)
  {
    res++;
    n /= 10;
  }
  return res;
}

void solve()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  vector<int> len(n);
  vector<ll> pw(11);
  pw[0] = 1;
  for (int i = 0; i < 10; i++)
  {
    pw[i + 1] = (pw[i] * 10) % k;
  }

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    len[i] = findNumOfDigits(a[i]);
  }

  vector<vector<ll>> rems(11);
  for (int i = 0; i < n; i++)
  {
    rems[findNumOfDigits(a[i])].push_back(a[i] % k);
  }

  for (int i = 0; i < 11; i++)
  {
    sort(rems[i].begin(), rems[i].end());
  }

  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j <= 10; j++)
    {
      ll rem = (a[i] * (ll)pw[j]) % k; // 第一項
      ll xrem = (k - rem) % k;
      ans += upper_bound(rems[j].begin(), rems[j].end(), xrem) - lower_bound(rems[j].begin(), rems[j].end(), xrem);
      if (len[i] == j && (rem + a[i] % k) % k == 0)
        ans--; // jの長さがa[i]自身と等しくなりかつ第一項とa[i]自身の和がmodで0となりansに含まれてしまっていたらそれを除く
    }
  }
  cout << ans << endl;
}

// conc(ai, aj) = ai * 10^lenj + ajとする
// You also might have calculated some pairs (i,i), iterate over them and subtract them naively.

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
