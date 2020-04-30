#include <bits/stdc++.h>
using namespace std;

int main()
{
  string X;
  cin >> X;
  bool can = true;
  for (int i = 0; i < X.size(); i++)
  {
    if (X[i] == 'c')
    {
      if (X[i + 1] == 'h')
      {
        i++;
        continue;
      }
      else
      {
        can = false;
        break;
      }
    }
    else if (X[i] == 'o')
      continue;
    else if (X[i] == 'k')
      continue;
    else if (X[i] == 'u')
      continue;
    else
    {
      can = false;
      break;
    }
  }
  if (can)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
