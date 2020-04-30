#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int N;
  cin >> N;
  int rem = 2025 - N;
  for (int i = 1; i <= 9; i++)
  {
    int ans1 = i;
    if (rem % i == 0)
    {
      int ans2 = rem / i;
      if (ans2 <= 9)
        cout << ans1 << " x " << ans2 << endl;
    }
  }
}
