#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  int ans;
  for (int i = N; i >= 0; i--)
  {
    double root = sqrt(i);
    if (floor(root) == ceil(root))
    {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}

// sqrt == 切り上げか切り下げになればいいのでは
