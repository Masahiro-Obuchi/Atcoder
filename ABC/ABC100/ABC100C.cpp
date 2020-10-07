#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long int> a(N);
  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  long long int ans = 0;
  for (int i = 0; i < N; i++)
  {
    while (a[i] % 2 == 0)
    {
      a[i] /= 2;
      ans++;
    }
  }
  cout << ans << endl;
}
