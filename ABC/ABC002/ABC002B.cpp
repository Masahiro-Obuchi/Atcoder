#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  string W;
  cin >> W;
  string ans;
  for (int i = 0; i < W.size(); i++)
  {
    if (W[i] == 'a' or W[i] == 'i' or W[i] == 'u' or W[i] == 'e' or W[i] == 'o')
      continue;
    else
      ans.push_back(W[i]);
  }
  cout << ans << endl;
}
