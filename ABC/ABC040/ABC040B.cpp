#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int rem, length, width;
  int ans = 100000000;
  for (int i = 1; i <= n; i++)
  {
    length = i;
    for (int j = 1; j * i <= n; j++)
    {
      width = j;
      int rec = i * j;
      rem = n - rec;
      int sum = abs(j - i) + rem;
      ans = min(ans, sum);
    }
  }
  cout << ans << endl;
}
