#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  string S, T;
  cin >> S >> T;
  string ans;
  int L = S.size() * 2;
  for (int i = 0; i < L; i++)
  {
    if (i % 2 == 0)
      ans.push_back(S[i / 2]);
    else
      ans.push_back(T[i / 2]);
  }
  cout << ans << endl;
}
