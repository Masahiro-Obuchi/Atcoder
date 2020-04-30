#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  int max = 0;
  sort(A.begin(), A.end(), greater<int>());
  max = A[0];
  int ans = 0;
  for (int i = 1; i < A.size(); i++)
  {
    if (A[i] != max)
    {
      ans = A[i];
      break;
    }
  }
  cout << ans << endl;
}
