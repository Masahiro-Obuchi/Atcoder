#include <bits/stdc++.h>
using namespace std;

int main()
{
  const int t = 753;
  string S;
  cin >> S;
  int ans = 1000;
  for (int i = 0; i < S.size() - 2; i++)
  {
    string str = S.substr(i, 3);
    int now = stoi(str);
    int res = abs(t - now);
    ans = min(res, ans);
  }
  cout << ans << endl;
}
