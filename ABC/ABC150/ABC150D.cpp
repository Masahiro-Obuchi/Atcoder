#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

long long int lcm(long long int a, long long int b)
{
  long long int g = gcd(a, b);
  return a / g * b;
}

int main()
{
  long long int N, M;
  cin >> N >> M;
  vector<long long int> a(N);
  for (int i = 0; i < N; i++)
  {
    long long int b;
    cin >> b;
    b /= 2;
    a[i] = b;
  }
  bool can = true;
  long long int num = 0;
  long long int div = 2;
  while (a[0] % div == 0) {
    num++;
    div *= 2;
  }
  for (int i = 1; i < N; i++)
  {
    long long int tmp = 0;
    div = 2;
    while (a[i] % div == 0) {
      tmp++;
      div *= 2;
    }
    if (tmp != num)
    {
      can = false;
      break;
    }
  }
  if (!can)
    cout << 0 << endl;
  else
  {
    long long int T = a[0];
    for (int i = 1; i < N; i++)
    {
      T = lcm(a[i], T);
    }
    long long int ans = (M / T + 1) / 2;
    cout << ans << endl;
  }
}

// 数学的な問題 X =  (ak / 2) * (2p + 1)としてXが(ak/2)の倍数でありXとakが2で割り切れる回数が等しくなることがポイント。ここからaiとajそれぞれの2で割り切れる回数が異なった場合、条件を満たすXは存在しないことがわかる。各akに関して2で割り切れる数が等しい場合XはM以下かつ(ak/2)の奇数倍となるため各akの最小公倍数をTとして(M / T + 1) /2が答えとなる。(MをTで割った答えがM以下のTの倍数の数。このうち2で割って切り上げたものが答えとなる) Tを更新する際に引数にTを入れることと、whileの条件式の中はdivにすることに注意