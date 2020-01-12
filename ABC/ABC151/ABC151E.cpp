
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

// 二項係数nCr
const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++)
  {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long COM(int n, int k)
{
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main()
{
  long long N, K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  long long ans = 0;
  COMinit();
  for (int i = 1; i <= N; i++)
  {
    long long nowMaxS = 0, nowMinS = 0;
    nowMaxS = COM(i - 1, K - 1);
    nowMinS = COM(N - i, K - 1);
    ans += ((A[i - 1] % MOD) * (nowMaxS % MOD) - (A[i - 1] % MOD) * (nowMinS % MOD)) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}

// Aを予めソートしておく．sigma(maxS - minS) = sigma(maxS) - sigma(minS)となることに着目して各Aiが何回maxS,minSとなるかを数え上げそれを足し上げる．
// 各Aiについて　maxS:SはAiを含みK-1個のAi未満の数を含む　i-1CK-1 minS:SはAiを含みK-1個のAiより大きい数を含む　なお，重複する数字が存在する場合も勝手な大小関係をつけて考えてよい（(Ai, i)の辞書順による順序を考えmaxS=(Ai, i)となる場合の数を数える）
