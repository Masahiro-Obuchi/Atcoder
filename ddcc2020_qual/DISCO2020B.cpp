#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  long long int ans = 1000000000000000;
  long long int sum = 0;
  vector<long long int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
    sum += A[i];
  }
  vector<long long int> S(N);
  S[0] = A[0];
  for (int i = 1; i < N; i++)
  {
    S[i] += S[i - 1] + A[i];
  }
  for (int i = 0; i < N - 1; i++)
  {
    long long int left = S[i];
    long long int right = sum - S[i];
    long long int now = 0;
    if (left >= right)
      now = left - right;
    else
      now = right - left;
    ans = min(now, ans);
  }
  cout << ans << endl;
}
