#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B;
  cin >> A >> B;
  int ans = 0;
  if (B / 10 == 0)
    ans = A * 10 + B;
  else if (B / 100 == 0)
    ans = A * 100 + B;
  else if (B / 1000 == 0)
    ans = A * 1000 + B;

  ans *= 2;
  cout << ans << endl;
}
