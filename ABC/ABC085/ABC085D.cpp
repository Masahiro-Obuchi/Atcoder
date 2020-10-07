#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N, H;
  cin >> N >> H;
  vector<ll> a(N), b(N);
  for (int i = 0; i < N; i++)
    cin >> a[i] >> b[i];
  sort(a.begin(), a.end(), greater<ll>());
  sort(b.begin(), b.end());
  int index = upper_bound(b.begin(), b.end(), a[0]) - b.begin();
  ll ans = 0;
  for (int i = N - 1; i >= index; i--)
  {
    H -= b[i];
    ans++;
    if (H <= 0)
      break;
  }
  if (H > 0)
  {
    ans += (H + a[0] - 1) / a[0];
  }
  cout << ans << endl;
  return 0;
}

// 投げる方が強いやつはとりあえず投げとく
// ai <= biであるから最後に投げるのは確定
// aは何回も使えるがbは1回しか使えない
// aを大きい順にソートして，bを小さい順にソートする．aの最も大きいものより大きくなるbのindexを二分探索で特定
// Hが0以下になるまでbを大きいものからindexまで取っていく．もし，H > 0ならHをa[0]で割った切り上げを答えに加算する．
