#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  long long N, T;
  cin >> N >> T;
  vector<long long> t(N);
  for (int i = 0; i < N; i++)
    cin >> t[i];
  long long ans = 0;
  for (int i = 0; i < N; i++)
  {
    if (i < N - 1)
    {
      if (t[i + 1] - t[i] > T)
        ans += T;
      else
        ans += t[i + 1] - t[i];
    }
    else
      ans += T;
  }
  cout << ans << endl;
}
