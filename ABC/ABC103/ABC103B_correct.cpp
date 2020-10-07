#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S, T;
  cin >> S >> T;
  bool ans = false;
  for (int i = 0; i < S.size(); i++)
  {
    if (S == T)
    {
      ans = true;
      break;
    }
    S = S.back() + S.substr(0, S.size() - 1);
  }
  if (ans)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
