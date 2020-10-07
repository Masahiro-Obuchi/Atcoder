#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int N, M;
  cin >> N >> M;
  unsigned long long int ans = 0;
  if (N == 1 && M == 1)
    ans = 1;
  else if (N == 1)
    ans = N * M - 2;
  else if (M == 1)
    ans = N * M - 2;
  else
    ans = N * M - (N * 2 + M * 2 - 4);
  cout << ans << endl;
}
