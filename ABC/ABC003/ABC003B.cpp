#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  string S, T;
  cin >> S >> T;
  bool can = true;
  string U = "atcoder";
  for (int i = 0; i < S.size(); i++)
  {
    if (S[i] == '@' and T[i] == '@')
      continue;
    else if (S[i] == '@' and T[i] != '@')
    {
      bool ok = false;
      for (int j = 0; j < U.size(); j++)
        if (T[i] == U[j])
          ok = true;
      if (!ok)
        can = false;
    }
    else if (T[i] == '@' and S[i] != '@')
    {
      bool ok2 = false;
      for (int j = 0; j < U.size(); j++)
        if (S[i] == U[j])
          ok2 = true;
      if (!ok2)
        can = false;
    }
    else if (S[i] != T[i])
      can = false;
  }
  if (can)
    cout << "You can win" << endl;
  else
    cout << "You will lose" << endl;
}
