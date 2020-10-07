#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  bool ans = true;
  if (S[0] != 'A')
    ans = false;
  string substr = S.substr(2, S.size() - 3);
  int ccnt = 0;
  int cindex = 0;
  for (int i = 0; i < substr.size(); i++)
  {
    if (substr[i] == 'C')
    {
      ccnt++;
      cindex = i + 2;
    }
  }
  if (ccnt != 1)
    ans = false;
  for (int i = 0; i < S.size(); i++)
  {
    if (i == 0 or i == cindex)
      continue;
    if (islower(S[i]) == 0)
      ans = false;
  }
  if (ans)
    cout << "AC" << endl;
  else
    cout << "WA" << endl;
}
