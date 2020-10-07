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
  ll N, A, B;
  cin >> N >> A >> B;
  vector<ll> X(N);
  for (auto &it : X)
    cin >> it;
  ll ans = 0;
  for (int i = 1; i < N; i++)
  {
    if (A * (X[i] - X[i - 1]) <= B)
      ans += A * (X[i] - X[i - 1]);
    else
      ans += B;
  }
  cout << ans << endl;
  return 0;
}

// まず，AとBの比較　
// 貪欲
