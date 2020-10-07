#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  ll ans = 0;
  if (K == 0)
  {
    ans = pow(N, 2);
  }
  else
  {
    for (int i = K + 1; i <= N; i++) // b
    {
      ans += (i - K) * (N / i) + max(0, N % i - (K - 1));
    }
  }
  cout << ans << endl;
  return 0;
}

// サンプルケース見て実験してたら出来た．bの値をK + 1からNまでで決め打ちして考える．K = 0のときはNを2倍してそれ以外の時は(i - K) * (N / i)をして更にmax(0, N % i - (K - 1))をする．(i - K)はi以下のK以上のもので，更にそれが周期的に続くからNをiで割った切り捨てまでかけ続けて，余りの分はN % iから(K - 1)と0の大きい方を引いたものを足す．
