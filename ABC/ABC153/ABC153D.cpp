
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main()
{
  long long int H;
  cin >> H;
  long long int cnt = 0;
  while (H > 0)
  {
    H /= 2;
    cnt++;
  }
  long long ans = (long long)pow(2, cnt) - 1;
  cout << ans << endl;
}
