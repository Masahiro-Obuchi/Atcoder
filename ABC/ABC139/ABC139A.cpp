#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  string S, T;
  cin >> S >> T;
  int ans = 0;
  for (int i = 0; i < S.size(); i++)
    if (S[i] == T[i])
      ans++;
  cout << ans << endl;
}
