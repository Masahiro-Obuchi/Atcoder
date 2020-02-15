#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

long long gcd(long long a, long long b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

vector<long long> divisor(long long n)
{
  vector<long long> ret;
  for (long long i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      ret.push_back(i);
      if (i * i != n)
        ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

bool isPrime(long long num)
{
  if (num < 2)
    return false;
  else if (num == 2)
    return true;
  else if (num % 2 == 0)
    return false;

  double sqrtNum = sqrt(num);

  for (int i = 3; i <= (int)sqrtNum; i++)
  {
    if (num % i == 0)
      return false;
  }

  return true;
}

int main()
{
  long long A, B;
  cin >> A >> B;
  long long N = gcd(A, B);
  vector<long long> commonDivisor = divisor(N);
  int ans = 0;
  for (int i = 0; i < commonDivisor.size(); i++)
  {
    if (isPrime(commonDivisor[i]))
      ans++;
  }
  cout << ans + 1 << endl; // 1はどれとも互いに素なので1を含める
}

// 最大公約数に着目する．（最大公約数の約数は公約数となるから）最大公約数を求めた後にその約数を列挙し，その全てを素数判定？
// A, Bの約数 = GCD(A, B)の約数
