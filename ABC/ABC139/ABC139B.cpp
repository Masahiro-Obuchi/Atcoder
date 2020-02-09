#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int A, B;
  cin >> A >> B;
  if (B == 1)
    cout << 0 << endl;
  else if (A >= B)
    cout << 1 << endl;
  else
  {
    int ans = 0;
    int num = 1;
    while (num < B)
    {
      num += A - 1;
      ans++;
    }
    cout << ans << endl;
  }
}
