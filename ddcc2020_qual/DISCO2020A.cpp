#include <bits/stdc++.h>
using namespace std;

int main()
{
  int X, Y;
  cin >> X >> Y;
  int ans = 0;
  if (X == 1)
    ans += 300000;
  if (Y == 1)
    ans += 300000;
  if (X == 2)
    ans += 200000;
  if (Y == 2)
    ans += 200000;
  if (X == 3)
    ans += 100000;
  if (Y == 3)
    ans += 100000;
  if (X == 1 && Y == 1)
    ans += 400000;
  cout << ans << endl;
}
