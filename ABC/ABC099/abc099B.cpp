#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  long long int l = 0;
  for (int i = b - a; i >= 1; i--)
  {
    l += i;
  }
  int ans = l - b;
  cout << ans << endl;
}
