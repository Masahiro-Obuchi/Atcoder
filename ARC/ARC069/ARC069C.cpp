#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int N, M;
  cin >> N >> M;
  long long int ans = 0;
  if (M / 2 <= N)
  {
    ans = M / 2;
  }
  else
  {
    ans = (M / 2 - N) / 2 + N;
  }
  cout << ans << endl;
}
