#include <bits/stdc++.h>
using namespace std;

int main()
{
  int L, H;
  cin >> L >> H;
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  vector<int> ans(N);
  for (int i = 0; i < N; i++)
  {
    if (A[i] > H)
      ans[i] = -1;
    else if (A[i] < L)
      ans[i] = L - A[i];
    else
      ans[i] = 0;
  }
  for (int i = 0; i < N; i++)
  {
    cout << ans[i] << endl;
  }
}
