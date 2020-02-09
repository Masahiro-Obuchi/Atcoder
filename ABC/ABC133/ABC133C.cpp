#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int L, R;
  cin >> L >> R;
  if ((R - L + 1) >= 2019)
    cout << 0 << endl;
  else
  {
    long long int min_rem = 2019;
    for (long long int i = L; i <= R - 1; i++)
    {
      for (long long int j = i + 1; j <= R; j++)
      {
        long long int product = i * j;
        long long int rem = product % 2019;
        min_rem = min(min_rem, rem);
      }
    }
    cout << min_rem << endl;
  }
}
