#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  string S;
  cin >> N >> S;
  bool can = true;
  int n = (N - 1) / 2;
  if (S == "b")
  {
    cout << 0 << endl;
  }
  else
  {
    if (n % 3 == 1)
    {
      if (!(S[0] == 'a' && S[N - 1] == 'c'))
        can = false;
    }
    else if (n % 3 == 2)
    {
      if (!(S[0] == 'c' && S[N - 1] == 'a'))
        can = false;
    }
    else
    {
      if (!(S[0] == 'b' && S[N - 1] == 'b'))
        can = false;
    }
    for (int i = 0; i < N; i++)
    {
      if (S[i - 1] == 'a' && !(S[i] == 'b'))
        can = false;
      else if (S[i - 1] == 'b' && !(S[i] == 'c'))
        can = false;
      else if (S[i - 1] == 'c' && !(S[i] == 'a'))
        can = false;
    }
    if (!can)
      cout << -1 << endl;
    else
    {
      cout << (N - 1) / 2 << endl;
    }
  }
}
