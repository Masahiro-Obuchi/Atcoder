#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}

const long long INF = 1LL << 60;
const int factor[3] = {2, 3, 5};
double dp[101][64][64][64] = {0}; // 2^60 ≒ 10^18

int main()
{
  long long N, D;
  cin >> N >> D;
  vector<int> cnt(3);
  for (int i = 0; i < 3; i++)
  {
    while (D % factor[i] == 0)
    { // Dがfactor[i]で割れる間
      cnt[i]++;
      D /= factor[i];
    }
  }
  if (D > 1)
  {
    cout << 0 << endl;
    return 0;
  }

  dp[0][0][0][0] = 1;
  const int dx[6] = {0, 1, 0, 2, 0, 1};
  const int dy[6] = {0, 0, 1, 0, 0, 1};
  const int dz[6] = {0, 0, 0, 0, 1, 0};
  for (int i = 0; i <= N; i++)
  {
    for (int j = 0; j <= cnt[0]; j++)
    {
      for (int k = 0; k <= cnt[1]; k++)
      {
        for (int l = 0; l <= cnt[2]; l++)
        {
          for (int m = 0; m < 6; m++)
          {
            int nx = min(cnt[0], j + dx[m]);
            int ny = min(cnt[1], k + dy[m]);
            int nz = min(cnt[2], l + dz[m]);
            dp[i + 1][nx][ny][nz] += dp[i][j][k][l] / 6.0;
          }
        }
      }
    }
  }
  cout << fixed << setprecision(10) << dp[N][cnt[0]][cnt[1]][cnt[2]] << endl;
}

// i回サイコロを振って素因数分解すると2がa回、3がb回、5がc回現れるような数になる確率を dp[i][a][b][c] とする。まず、Dに2, 3, 5以外の素因数が現れたらその時点でアウト。ある目が出た時に各素因数の数がどれだけ増えるかの配列を作る。サイコロの目を1から6までループさせて増えたa, b, cの数と各々の出現回数とのminをそれぞれna, nb, ncとする。dp[i+1][na][nb][nc]はdp[i][a][b][c]に1/6をかけたもの。どこかからdp[i+1][na][nb][nc]に到達する場合の数は1通りではないからdp[i+1][na][nb][nc] += dp[i][a][b][c] / 6.0としてサイコロを振った数i, 2が出た数a, 3が出た数b, 5が出た数c, サイコロの目mでループを回して全通りを試す。