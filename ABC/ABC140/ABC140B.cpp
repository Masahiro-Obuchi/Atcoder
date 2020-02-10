#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N), B(N), C(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];
  for (int i = 0; i < N; i++)
    cin >> B[i];
  for (int i = 0; i < N - 1; i++)
    cin >> C[i];
  int ans = 0;
  int prev = -1;
  for (int i = 0; i < N; i++)
  {
    if (i == 0)
    {
      ans += B[A[i] - 1];
      prev = A[i] - 1;
    }
    else
    {
      ans += B[A[i] - 1];
      if (A[i] - 1 == prev + 1)
        ans += C[prev];
      prev = A[i] - 1;
    }
  }
  cout << ans << endl;
}
