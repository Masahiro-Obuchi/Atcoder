#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B;
  cin >> A >> B;
  string S;
  cin >> S;
  bool ok = true;
  for (int i = 0; i < S.size(); i++)
  {
    if (i == A)
    {
      if (S[i] != '-')
      {
        ok = false;
        break;
      }
    }
    else
    {
      if (S[i] == '-')
      {
        ok = false;
        break;
      }
    }
  }
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
