#include <bits/stdc++.h>
using namespace std;

int digitNum(long long int N)
{
  int num = 0;
  while (N > 0)
  {
    N /= 10;
    num++;
  }
  return num;
}

int main()
{
  long long int A, B, X;
  cin >> A >> B >> X;
  if (A > X or B > X)
    cout << 0 << endl;
  else if (A * 1000000000 + B * 10 <= X)
    cout << 1000000000 << endl;
  else
  {
    long long int ans = 0;
    long long int start = (X - 10 * B) / A;
    for (long long int N = start; N <= 1000000000; N++)
    {
      if (A * N + B * digitNum(N) <= X)
        ans = max(N, ans);
      else
        break;
    }
    cout << ans << endl;
  }
}

// 嘘解法！！！値段に単調性があるので二分探索を用いることが出来る
//
