#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  string S;
  cin >> S;
  int now = 0;
  int ans = 0;
  for (int i = 0; i < S.size(); i++)
  {
    if (S[i] == 'I')
      now++;
    else
      now--;
    ans = max(now, ans);
  }
  cout << ans << endl;
}
