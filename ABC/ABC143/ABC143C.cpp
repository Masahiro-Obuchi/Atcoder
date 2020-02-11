#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int N;
  string S;
  cin >> N >> S;
  char now = S[0];
  int ans = 1;
  for (int i = 1; i < N; i++)
  {
    if (now != S[i])
      ans++;
    now = S[i];
  }
  cout << ans << endl;
}
