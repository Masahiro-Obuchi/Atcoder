#include <bits/stdc++.h>
using namespace std;

bool digitSame(int n)
{
  bool same = false;
  int a, b, c;
  a = n % 10;
  n /= 10;
  b = n % 10;
  n /= 10;
  c = n % 10;
  if (a == b and b == c)
    same = true;
  return same;
}

int main()
{
  int N;
  cin >> N;
  int ans = 0;
  for (int i = N; i < 2000; i++)
  {
    if (digitSame(i))
    {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}
