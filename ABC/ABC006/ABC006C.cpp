#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  for (int z = 0; z <= M; z++)
  {
    int y = M - 2 * N - 2 * z;
    int x = 3 * N - M + z;
    if (x >= 0 && y >= 0)
    {
      cout << x << " " << y << " " << z << endl;
      return 0;
    }
  }
  cout << -1 << " " << -1 << " " << -1 << endl;
  return 0;
}

// xとyについて見るのではなくNとMについて見た方が式が楽（制約に合うかどうかを見るのが）
