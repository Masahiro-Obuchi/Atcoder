#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  int ans = 1000000000;
  for (int bit = 0; bit < (1 << N); bit++)
  {
    int tmp = 1;
    for (int i = 0; i < N; i++)
    {
      if (bit & (1 << i))
      { // i が bitに入るかどうか
        tmp *= 2;
      }
      else
        tmp += K;
    }
    ans = min(tmp, ans);
  }
  cout << ans << endl;
}

// bit全探索？
