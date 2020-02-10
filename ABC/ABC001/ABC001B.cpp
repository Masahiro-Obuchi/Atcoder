#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int m;
  cin >> m;
  string ans;
  if (m < 100)
    ans = "00";
  else if (m >= 100 and m <= 5000)
  {
    if (m < 1000)
      ans = "0" + to_string(m / 100);
    else
      ans = to_string(m / 100);
  }
  else if (m >= 6000 and m <= 30000)
    ans = to_string(m / 1000 + 50);
  else if (m >= 35000 and m <= 70000)
    ans = to_string((m / 1000 - 30) / 5 + 80);
  else
    ans = "89";
  cout << ans << endl;
}
