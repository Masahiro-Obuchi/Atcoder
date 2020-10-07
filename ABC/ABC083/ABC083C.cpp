#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int X, Y;
  cin >> X >> Y;
  long long int ans = 0;
  while (X <= Y)
  {
    ans++;
    X *= 2;
  }
  cout << ans << endl;
}

// XがYを超えない間，2をかけ続ければOK. ansを1で初期化し，2をかけ範囲内にあればansをインクリメントする．
