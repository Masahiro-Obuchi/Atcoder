#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S, T;
  cin >> S >> T;
  bool can = false;
  for (int i = 0; i < S.size(); i++)
  {
    char tmp = S[S.size() - 1];
    for (int j = S.size() - 1; j >= 1; j--)
    {
      S[j] = S[j - 1];
    }
    S[0] = tmp;
    if (S == T)
    {
      can = true;
      break;
    }
  }
  if (can)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
