#include <bits/stdc++.h>
using namespace std;

int main()
{
  string O, S;
  cin >> O >> S;
  for (int i = 0; i < O.size(); i++)
  {
    if (O.size() - S.size() == 1 and i == O.size() - 1)
    {
      cout << O.at(i);
    }
    else
    {
      cout << O.at(i);
      cout << S.at(i);
    }
  }
}
