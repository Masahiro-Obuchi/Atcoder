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
  int N, K;
  cin >> N >> K;
  vector<ll> a(N);
  for (auto &ai : a)
    cin >> ai;
  ll ans = 0;
  ll tmp = 0;
  for (int i = 0; i < K; i++)
    tmp += a[i];
  ans += tmp;
  for (int i = 1; i < N - K + 1; i++)
  {
    tmp -= a[i - 1];
    tmp += a[i + K - 1];
    ans += tmp;
  }
  cout << ans << endl;
  return 0;
}

// 尺取り法
