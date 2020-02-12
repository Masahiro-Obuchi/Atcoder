#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  string S;
  cin >> S;
  bool ok = true;
  for (int i = 0; i < S.size(); i++)
  {
    if (i % 2 == 0)
    {
      if (!(S[i] == 'R' || S[i] == 'U' || S[i] == 'D'))
        ok = false;
    }
    else
    {
      if (!(S[i] == 'L' || S[i] == 'U' || S[i] == 'D'))
        ok = false;
    }
  }
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
