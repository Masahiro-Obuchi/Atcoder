#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

long long int lcm(long long int a, long long int b)
{
  long long int g = gcd(a, b);
  return a / g * b;
}

int main()
{
  int N;
  cin >> N;
  vector<long long int> T(N);
  for (int i = 0; i < N; i++)
  {
    cin >> T[i];
  }
  long long int ans = T[0];
  for (int i = 1; i < N; i++)
  {
    ans = lcm(ans, T[i]);
  }
  cout << ans << endl;
}
