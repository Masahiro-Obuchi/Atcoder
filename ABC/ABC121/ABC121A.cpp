#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int H, W;
  cin >> H >> W;
  int h, w;
  cin >> h >> w;
  int ans = (H - h) * (W - w);
  cout << ans << endl;
}
