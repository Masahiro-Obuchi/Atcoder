#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  double D;
  cin >> D >> N;
  double a = pow(100.0, D);
  int ans;
  if (N <= 99)
    ans = a * N;
  else if (N = 100)
    ans = 101 * a;

  cout << ans << endl;
}

// 方針2 条件に当てはまる数を列挙　100でちょうど割り切れるような数は，a = 100^Dとして，最初100個はa, 2a, 3a, 4a, ..., 99a, 101aになる．したがって，N<=100を仮定するとN<=99のときNa = N*100^Dが答えとなり，N=100のとき101a = 101*100^Dが答えとなる(100aは100^(D+1)となってしまうためにちょうどD回割れることにならない，D+1回割ることが出来てしまう．したがって100aの場合を飛ばし，100個目は101aとなる) 100でちょうどD回割り切れるもののうち，N番目に小さいものが求めるもの
