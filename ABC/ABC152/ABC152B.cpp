
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main()
{
  int a, b;
  cin >> a >> b;
  string ans1, ans2;
  for (int i = 0; i < a; i++)
  {
    char c = '0' + b;
    ans1 += c;
  }
  for (int i = 0; i < b; i++)
  {
    char c = '0' + a;
    ans2 += c;
  }
  if (ans1 <= ans2)
    cout << ans1 << endl;
  else
    cout << ans2 << endl;
}
