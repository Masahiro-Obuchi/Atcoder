
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main()
{
  int H, W, N;
  cin >> H >> W >> N;
  int cnt = 0;
  while (N > 0)
  {
    N -= max(H, W);
    cnt++;
  }
  cout << cnt << endl;
}
