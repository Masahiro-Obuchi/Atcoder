#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  string S;
  cin >> N >> S;
  for (int i = 0; i < S.size(); i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (S[i] == 'Z')
      {
        S[i] = 'A';
      }
      else
      {
        S[i]++;
      }
    }
  }
  cout << S << endl;
}
