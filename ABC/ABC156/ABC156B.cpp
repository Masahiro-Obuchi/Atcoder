#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  long long N, K;
  cin >> N >> K;
  long long ans = 0;
  while (N > 0)
  {
    N /= K;
    ans++;
  }
  cout << ans << endl;
}
