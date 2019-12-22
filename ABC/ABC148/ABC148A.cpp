#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B;
  cin >> A >> B;
  int ans = 0;
  for (int i = 1; i <= 3; i++)
  {
    if (i != A && i != B)
      ans = i;
  }
  cout << ans << endl;
}
