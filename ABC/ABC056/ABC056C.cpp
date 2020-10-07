#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int X = 0;
  cin >> X;
  long long int ans = 0, now = 0, i = 1;
  while (now < X)
  {
    now += i;
    i++;
  }
  ans = i - 1;
  cout << ans << endl;
}
