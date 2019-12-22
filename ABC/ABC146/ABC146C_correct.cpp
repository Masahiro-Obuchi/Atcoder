#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll A, B, X;
  cin >> A >> B >> X;
  ll l = 0, r = 1000000001; // l : o, r : x
  auto keta = [&](ll c) {
    int res = 0;
    while (c > 0)
    {
      c /= 10;
      res++;
    }
    return res;
  };
  auto f = [&](ll c) { // ラムダ式 とりあえず競プロでは&入れとけばいい．
    return A * c + B * keta(c);
  };
  while (r - l > 1)
  {
    ll c = (l + r) / 2;
    if (f(c) <= X)
      l = c;
    else
      r = c;
  }
  cout << l << endl;
}
