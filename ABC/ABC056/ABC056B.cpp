#include <bits/stdc++.h>
using namespace std;

int main()
{
  int W, a, b;
  cin >> W >> a >> b;
  if (a < b)
  {
    if (b - (a + W) <= 0)
      cout << 0 << endl;
    else
      cout << b - (a + W) << endl;
  }
  else
  {
    if (a - (b + W) <= 0)
      cout << 0 << endl;
    else
      cout << a - (b + W) << endl;
  }
}
