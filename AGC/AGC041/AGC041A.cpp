#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int N, A, B;
  cin >> N >> A >> B;
  long long int ans = 1LL << 60;
  if ((max(A, B) - min(A, B)) % 2 == 0)
  {
    ans = (max(A, B) - min(A, B)) / 2;
  }
  else
  {
    long long int ans1, ans2 = 0;
    ans1 = min(A, B) + (max(A, B) - min(A, B) - 1) / 2;
    ans2 = N - max(A, B) + 1 + (max(A, B) - min(A, B) - 1) / 2;
    ans = min(min(ans, ans1), ans2);
  }
  cout << ans << endl;
}
// 折り返して来るパターン
