#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int A, B, K, L;
  cin >> A >> B >> K >> L;
  long long int ans;
  long long int set_num = K / L;
  long long int num = K % L;
  long long int ceil_num = (K + (L - 1)) / L;
  ans = min(A * K, min((B * set_num + A * num), B * ceil_num));
  cout << ans << endl;
}
