#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, T;
  cin >> N >> T;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  int ans = 0;
  for (int i = 0; i < N - 1; i++)
  {
    if (A[i + 1] - A[i] >= T)
      ans += T;
    else
      ans += A[i + 1] - A[i];
  }
  ans += T;
  cout << ans << endl;
}
