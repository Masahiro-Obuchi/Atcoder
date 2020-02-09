#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int N;
  cin >> N;
  long long int ans = 0;
  for (int i = 0; i < N; i++)
  {
    ans += i;
  }
  cout << ans << endl;
}
