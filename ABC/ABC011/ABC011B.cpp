#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  for (int i = 0; i < S.size(); i++)
  {
    if (i == 0)
      S[i] = toupper(S[i]);
    else
      S[i] = tolower(S[i]);
  }
  cout << S << endl;
}
