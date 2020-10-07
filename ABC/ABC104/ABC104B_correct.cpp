#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  int L = S.size();
  string ans = "AC";
  if (S[0] != 'A')
  {
    ans = "WA";
  }
  int cnt = 0;
  for (int i = 1; i < L; i++)
  {
    if (isupper(S[i]))
    {
      if (i == 1 or i == L - 1 or S[i] != 'C')
      {
        ans = "WA";
      }
      ++cnt;
    }
  }
  if (cnt != 1)
  {
    ans = "WA";
  }
  cout << ans << endl;
}
