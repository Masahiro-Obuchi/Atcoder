#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int N;
  cin >> N;
  vector<int> X(N);
  for (int i = 0; i < N; i++)
    cin >> X[i];
  long long ans = 1000000000000;
  for (int i = 0; i <= 100; i++)
  {
    long long sum = 0;
    for (int j = 0; j < X.size(); j++)
    {
      sum += (i - X[j]) * (i - X[j]);
    }
    if (ans > sum)
    {
      ans = min(sum, ans);
    }
  }
  cout << ans << endl;
}
