#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int t = 0;
  cin >> t;
  vector<long long int> ans(t);
  for (int i = 0; i < t; i++)
  {
    long long int n, k;
    cin >> n >> k;
    long long int a = n / k;
    long long int b = n / k + 1;
    long long int m = 0;
    m = a * k;
    long long int l = 0;
    l = n % k;
    long long int s = 0;
    if (l >= k / 2)
      s = k / 2;
    else
      s = l;
    ans[i] = m + s;
  }
  for (int i = 0; i < t; i++)
  {
    cout << ans[i] << endl;
  }
}
