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
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (auto &it : A)
    cin >> it;
  int len = 1;
  int ans = 0;
  for (int i = 1; i < N; i++)
  {
    if (A[i] > A[i - 1])
      len++;
    else
    {
      ans += max(0, len - K + 1);
      len = 1;
    }
  }
  ans += max(0, len - K + 1);
  cout << ans << endl;
  return 0;
}

// 常に上昇している数列に分解　K以上ならば長さ - K + 1をする．
