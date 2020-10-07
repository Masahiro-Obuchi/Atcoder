#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main()
{
  int N;
  cin >> N;
  vector<long long int> a(N);
  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  long long int ans;
  ans = gcd(a[0], a[1]);
  for (int i = 2; i < N; i++)
  {
    ans = gcd(ans, a[i]);
  }
  cout << ans << endl;
}
