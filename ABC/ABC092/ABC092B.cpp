#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, D, X;
  cin >> N >> D >> X;
  vector<int> A(N);
  for (auto &a : A)
  {
    cin >> a;
  }
  int sum = X;
  for (int i = 0; i < N; i++)
  {
    int days = 1;
    int j = 0;
    while (days <= D)
    {
      sum += 1;
      days += A[i];
      j++;
    }
  }
  cout << sum << endl;
}
