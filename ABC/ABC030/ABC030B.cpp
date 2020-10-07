#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  double deg1, deg2;
  n %= 12;
  double ans = 0.0;
  deg1 = 30 * n + 0.5 * m;
  deg2 = 6.0 * m;
  ans = min(abs(deg1 - deg2), abs(deg2 - deg1));
  if (ans < 180)
    cout << ans << endl;
  else
    cout << 360 - ans << endl;
}

// ちゃんと図に書いて確認しないといけない
// 180度よりも大きいときは大きい方の角を見てしまっているため，360度から差の核を引いたものが答えとなる．
// 整数/整数は言語によっては切り捨てられてしまうため注意する．
// 問題文をよく読む，短針が1分で何度動くか，長針がどのくらい動くか，abs(deg1 - deg2)とans(deg2 - deg1)は同じじゃないか...???
