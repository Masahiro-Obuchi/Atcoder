#include <bits/stdc++.h>
using namespace std;

int main()
{
  string A;
  cin >> A;
  if (A.size() > 1)
  {
    string ans = A.substr(0, A.size() - 1);
    cout << ans << endl;
  }
  else
  {
    if (A[0] == 'a')
      cout << -1 << endl;
    else
    {
      string ans;
      ans = A[0] - 1;
      cout << ans << endl;
    }
  }
}
