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
  vector<int> A(3);
  for (auto &it : A)
    cin >> it;
  int ans = 1000;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (i == j)
        continue;
      for (int k = 0; k < 3; k++)
      {
        if (k == i or k == j)
          continue;
        int tmp = abs(A[j] - A[i]) + abs(A[k] - A[j]);
        ans = min(ans, tmp);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
