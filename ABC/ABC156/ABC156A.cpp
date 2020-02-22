#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int N, R;
  cin >> N >> R;
  int in = 0, disp = 0;
  if (N < 10)
  {
    disp = R;
    in = disp + 100 * (10 - N);
  }
  else
  {
    disp = R;
    in = R;
  }
  cout << in << endl;
}
