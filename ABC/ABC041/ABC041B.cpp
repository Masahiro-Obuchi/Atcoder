#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int INF = 1000000007;
  long long int A, B, C;
  cin >> A >> B >> C;
  long long int vol = (A * B) % INF;
  vol *= C;
  vol %= INF;
  long long int ans = vol % INF;
  cout << ans << endl;
}

// よく知られた剰余の性質
// (A * B)%M = {(A%M)*(B%M)}%M
// この性質を使うと(long long) A * B % 1000000007 * C % 10000000007という式で計算できる
