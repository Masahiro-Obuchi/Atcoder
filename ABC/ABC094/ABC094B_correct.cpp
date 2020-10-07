#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M, X;
  cin >> N >> M >> X;
  vector<int> A(M);
  for (auto &a : A)
  {
    cin >> a;
  }
  int left = 0;
  int right = 0;
  for (auto &a : A)
  {
    if (a < X)
      left++;
    else
      right++;
  }
  cout << min(left, right) << endl;
  return 0;
}
