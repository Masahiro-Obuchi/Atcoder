
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main()
{
  long long int H, N;
  cin >> H >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  long long int sum = 0;
  for (int i = 0; i < N; i++)
  {
    sum += A[i];
  }
  if (H > sum)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}
