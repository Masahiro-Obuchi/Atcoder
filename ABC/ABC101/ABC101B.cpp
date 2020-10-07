#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int n)
{
  int sum = 0;
  while (n > 0)
  {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main()
{
  int N;
  cin >> N;
  int S = sumOfDigits(N);
  if (N % S == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
