#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll d, n, m;
  cin >> d >> n >> m;
  vector<ll> D(n + 1);
  D[0] = 0;
  D[n] = d;
  for (int i = 1; i < n; i++)
    cin >> D[i];
  vector<ll> k(m);
  for (int i = 0; i < m; i++)
    cin >> k[i];

  ll ans = 0;

  sort(D.begin(), D.end());

  for (int i = 0; i < m; i++)
  {
    int back = lower_bound(D.begin(), D.end(), k[i]) - D.begin();
    int front = back - 1;
    if (back == 0)
      ans += D[back] - k[i];
    else
      ans += min(k[i] - D[front], D[back] - k[i]);
  }
  cout << ans << endl;
  return 0;
}

// 円周上のままだと考えにくいので最初の店舗が両端にあるような線分上で考える．配達先の両端であるような店舗を二分探索で求め，配達席から近い方の距離を加算していく．
