#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long int> a(N);
  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  vector<long long int> S(N);
  S[0] = a[0];
  for (int i = 1; i < N; i++)
  {
    S[i] = S[i - 1] + a[i];
  }
  long long int ans = 1LL << 60;
  for (int i = 0; i < N - 1; i++)
  {
    long long int x = S[i];
    long long int y = S[N - 1] - x;
    ans = min(ans, abs(x - y));
  }
  cout << ans << endl;
}
