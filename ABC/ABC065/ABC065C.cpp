#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int MOD = 1000000007;
  long long int N, M;
  cin >> N >> M;
  if (N - M >= 2 or M - N >= 2)
  {
    cout << 0 << endl;
  }
  else
  {
    if (N - M == 1 or M - N == 1)
    {
      long long int tmp1 = 1, tmp2 = 1;
      for (int i = 1; i <= N; i++)
      {
        tmp1 *= i;
        tmp1 %= MOD;
      }
      for (int i = 1; i <= M; i++)
      {
        tmp2 *= i;
        tmp2 %= MOD;
      }
      long long int ans = tmp1 * tmp2 % MOD;
      cout << ans << endl;
    }
    else
    {
      long long int tmp = 1;
      for (int i = 1; i <= N; i++)
      {
        tmp *= i;
        tmp %= MOD;
      }
      long long int ans = tmp * tmp % MOD;
      ans *= 2;
      ans %= MOD;
      cout << ans << endl;
    }
  }
}

// コメント
// やはり実装がへたくそ... N - M の絶対値が2以上のときは与えられた条件を満たすことはできない．N - M = 1のときは多い方を外側にして少ない方を内側にしてしまえば，仮に多い方をNとすると多い方の並べ方N!と少ない方の並べ方M!をかけてN!*M!. N = Mのときは各々の並べ方N!とM!を掛け合わせたうえでどちらから始めるかを考慮して*2. よって2*N!*M!.
