#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  long long N;
  cin >> N;
  vector<long long> d(N);
  for (int i = 0; i < N; i++)
    cin >> d[i];
  sort(d.begin(), d.end());
  long long ans = d[N / 2] - d[N / 2 - 1];
  if (ans > 0)
    cout << ans << endl;
  else
    cout << 0 << endl;
}
