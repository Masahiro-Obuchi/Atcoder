#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  long long N;
  cin >> N;
  vector<long long> B(N - 1);
  for (int i = 0; i < N - 1; i++)
    cin >> B[i];
  vector<long long> A(N);
  A[0] = B[0];
  A[N - 1] = B[N - 2];
  for (int i = 1; i < N - 1; i++)
  {
    A[i] = min(B[i], B[i - 1]);
  }
  long long ans = 0;
  for (int i = 0; i < N; i++)
  {
    ans += A[i];
  }
  cout << ans << endl;
}
