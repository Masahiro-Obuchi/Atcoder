#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  double N, K;
  cin >> N >> K;
  double denom = pow(N, 3);
  double numer = 6 * (K - 1) * (N - K) + 3 * (N - 1) + 1;
  double ans = numer / denom;
  cerr << numer << " " << denom << endl;
  cout << setprecision(20) << fixed << ans << endl;
  return 0;
}

// 1. Kが一つ出るとき Kより小さい数の選び方でK -1通り,Kより大きい数の選び方でN - K通り　並べ方で3! (K - 1) * (N - K) * 3!
// 2. Kが二つ出るとき K以外の数を置く場所の選び方で3C1通り，K以外の数の選び方でN - 1通り 3 * (N - 1)
// 3. Kが三つ出るとき 1通り
