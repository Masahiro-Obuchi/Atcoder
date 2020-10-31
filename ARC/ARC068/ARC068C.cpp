#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int x;
  cin >> x;
  long long int ans = 0;
  long long int eleven = x / 11;
  ans += eleven * 2;
  if (x % 11 == 0)
    cout << ans << endl;
  else
  {
    long long int rem = x % 11;
    if (rem > 6)
      ans += 2;
    else
      ans += 1;
    cout << ans << endl;
  }
}

// 初め5の面を上に向けてあとは6と5を繰り返すことに気付いてしまえば一瞬．xを11で割ったときの余りが0になるときはif文を使って場合を分けて先に出力しないとrem <= 6となったときにans += 1されてしまう．
