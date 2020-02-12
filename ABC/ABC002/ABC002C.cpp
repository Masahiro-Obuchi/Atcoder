#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  xb -= xa;
  yb -= ya;
  xc -= xa;
  yc -= ya;
  double ans = 1. / 2. * abs(xb * yc - yb * xc);
  cout << fixed << setprecision(10) << ans << endl;
}
