#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  ll ans = INF;
  for (int i = 0; i <= 300000; i++)
  {
    ll tmp = C * 2 * i + A * max(0LL, X - i) + B * max(0LL, Y - i);
    ans = min(tmp, ans);
  }
  cout << ans << endl;
  return 0;
}

// ハーフピザが何枚あるかで全探索
