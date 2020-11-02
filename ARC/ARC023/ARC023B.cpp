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

  int R, C, D;
  cin >> R >> C >> D;

  vector<vector<int>> A(R, vector<int>(C));
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      cin >> A[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      if (i + j <= D && (i + j) % 2 == D % 2)
        ans = max(ans, A[i][j]);
    }
  }

  cout << ans << endl;
  return 0;
}

// あるマス(i, j)を見た時にちょうどD回の移動で行けるかということを考える．
// マス(i, j)に行けるための条件は1. i+j <= D (遠すぎると行けない) 2. i+jとDの偶奇が一致．(1回の移動でi+jの値が奇数->偶数->奇数->偶数...と変わっていくから)
