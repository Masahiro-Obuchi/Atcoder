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
  long long int A, B;
  cin >> A >> B;
  long long int ans = lcm(A, B);
  cout << ans << endl;
}
