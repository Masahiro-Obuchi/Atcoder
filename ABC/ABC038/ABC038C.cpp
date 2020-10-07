#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> a(N);
  for (auto &ai : a)
    cin >> ai;
  ll ans = 0;
  bool increasing = true;
  int l = 0, r = 0;
  while (l <= N - 1)
  {
    while (r + 1 < N && a[r + 1] > a[r])
      r++;
    cerr << r << endl;
    ans += (r - l + 1);
    l++;
    if (l == r + 1)
      r++;
  }
  cout << ans << endl;
  return 0;
}

// 解説に沿った尺取り法
// lがrより大きくなったらr++
