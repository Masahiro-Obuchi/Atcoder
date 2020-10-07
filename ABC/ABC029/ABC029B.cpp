#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  int Acnt = 0, Bcnt = 0, Ccnt = 0, Dcnt = 0, Ecnt = 0, Fcnt = 0;
  for (int i = 0; i < S.size(); i++)
  {
    if (S[i] == 'A')
      Acnt++;
    else if (S[i] == 'B')
      Bcnt++;
    else if (S[i] == 'C')
      Ccnt++;
    else if (S[i] == 'D')
      Dcnt++;
    else if (S[i] == 'E')
      Ecnt++;
    else
      Fcnt++;
  }
  cout << Acnt << " " << Bcnt << " " << Ccnt << " " << Dcnt << " " << Ecnt << " " << Fcnt << endl;
}
