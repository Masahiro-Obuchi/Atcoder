#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int A, B, C;
  cin >> A >> B >> C;
  if ((A == B && B != C) or (A == C && B != C) or (A != B && B == C))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
