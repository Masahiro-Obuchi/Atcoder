#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  string S, T;
  cin >> S >> T;
  int A, B;
  cin >> A >> B;
  string U;
  cin >> U;
  int ans = 0;
  if (U == S)
    cout << A - 1 << " " << B << endl;
  else if (U == T)
    cout << A << " " << B - 1 << endl;
  else
    cout << A + B << endl;
}
