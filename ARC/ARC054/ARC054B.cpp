#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long double P;
  cin >> P;
  long double x = - 1.5 * log2(3. / (2 * P * log(2)));
  if (x < 0.0) cout << setprecision(12) << fixed << P << endl;
  else cout << setprecision(12) << fixed << x + P / pow(2, (x / 1.5)) << endl;
  return 0;
}

// 微分してf'が0になる値が負になる時はPを出力して，正になる時はfの値を出力する 普通に解析的に力技で解く　xが負になる場合に注意
