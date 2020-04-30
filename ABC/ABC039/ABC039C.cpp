#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  string ans;
  if (S[1] == 'B')
  {
    if (S[3] == 'W')
    {
      if (S[8] == 'B')
        ans = "Re";
      else
        ans = "La";
    }
    else
    {
      if (S[5] == 'B')
        ans = "Fa";
      else
      {
        if (S[10] == 'B')
          ans = "Do";
        else
          ans = "So";
      }
    }
  }
  else
  {
    if (S[6] == 'B')
      ans = "Mi";
    else
      ans = "Si";
  }
  cout << ans << endl;
}

// この問題はある場所の色に着目して地道に場合分けしていくしかない．
