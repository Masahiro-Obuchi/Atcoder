#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N + 2);
  A[0] = 0, A[N + 1] = 0;
  for (int i = 1; i < N + 1; i++)
  {
    cin >> A[i];
  }
  vector<long long int> ans(N);
  long long int sum = 0;
  for (int i = 1; i < N + 2; i++)
  {
    sum += abs(A[i] - A[i - 1]);
  }
  for (int i = 0; i < N; i++)
  {
    ans[i] = sum - abs(A[i + 1] - A[i]) - abs(A[i + 2] - A[i + 1]) + abs(A[i + 2] - A[i]);
  }
  for (int i = 0; i < N; i++)
  {
    cout << ans[i] << endl;
  }
}
