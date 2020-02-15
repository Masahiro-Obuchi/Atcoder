#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int A, B, C, D, E;
  cin >> A >> B >> C >> D >> E;
  cout << max(E + D + A, E + C + B) << endl;
}
