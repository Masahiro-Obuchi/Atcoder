#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  long long N;
  cin >> N;
  vector<long long> H(N);
  for (int i = 0; i < N; i++)
    cin >> H[i];
  long long ans = 0, cnt = 0;
  for (int i = 0; i < N - 1; i++)
  {
    if (H[i] >= H[i + 1])
      cnt++;
    else
      cnt = 0;
    ans = max(cnt, ans);
  }
  cout << ans << endl;
}
