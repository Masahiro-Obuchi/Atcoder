#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<ll> h(N);
  for (auto &it : h)
    cin >> it;
  int ans = 1;
  for (int i = 0; i < N; i++)
  {
    if (i == 0 || i == N - 1 || h[i - 1] < h[i] && h[i] > h[i + 1])
    {
      int s = i, u = i;
      for (int j = i - 1; j >= 0; j--)
      {
        if (h[j] < h[j + 1])
          s = j;
        else
          break;
      }
      for (int j = i + 1; j < N; j++)
      {
        if (h[j - 1] > h[j])
          u = j;
        else
          break;
      }
      ans = max(ans, u - s + 1);
    }
  }
  cout << ans << endl;
  return 0;
}

// tを固定してsとuを出来るだけ両端に伸ばす．固定するtの条件は山の頂点となりうるh[i - 1] < h[i] && h[i] > h[i + 1]となるiのみを考えると満点を取ることが出来る．
