#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int N)
{
  int sum = 0;
  while (N > 0)
  {
    sum += N % 10;
    N /= 10;
  }
  return sum;
}

int main()
{
  int N, A, B;
  cin >> N >> A >> B;
  int sum = 0;
  for (int i = 1; i <= N; i++)
  {
    if (A <= sumOfDigits(i) and sumOfDigits(i) <= B)
    {
      sum += i;
    }
  }
  cout << sum << endl;
}
