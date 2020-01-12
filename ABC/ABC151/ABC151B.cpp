#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main()
{
  int N, K, M;
  cin >> N >> K >> M;
  vector<int> a(N - 1);
  for (int i = 0; i < N - 1; i++)
  {
    cin >> a[i];
  }
  int sum = 0;
  for (int i = 0; i < N - 1; i++)
  {
    sum += a[i];
  }
  int ans = M * N - sum;
  if (M * N < sum)
    cout << 0 << endl;
  else if (ans > K)
    cout << -1 << endl;
  else
  {
    cout << ans << endl;
  }
}
