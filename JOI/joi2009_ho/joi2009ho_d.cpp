#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
// using Graph = vector<vector<Edge>>;
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int grid[1010][1010];
int dp[1010][1010];
int nGrid[1010][1010];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W, N;
  while (true)
  {
    for (int i = 0; i < H; i++)
    {
      for (int j = 0; j < W; j++)
      {
        grid[i][j] = 0;
      }
    }
    for (int i = 0; i < H + 1; i++)
    {
      for (int j = 0; j < W + 1; j++)
      {
        dp[i][j] = 0;
      }
    }
    for (int i = 0; i < H; i++)
    {
      for (int j = 0; j < W; j++)
      {
        nGrid[i][j] = 0;
      }
    }

    cin >> H >> W >> N;
    if (H == W && W == N)
      break;

    for (int i = 0; i < H; i++)
    {
      for (int j = 0; j < W; j++)
      {
        cin >> grid[i][j];
      }
    }

    dp[0][0] = N - 1;

    for (int i = 0; i < H; i++)
    {
      for (int j = 0; j < W; j++)
      {
        if (grid[i][j])
        {
          dp[i + 1][j] += dp[i][j] / 2;
          dp[i][j + 1] += (dp[i][j] + 1) / 2;
        }
        else
        {
          dp[i + 1][j] += (dp[i][j] + 1) / 2;
          dp[i][j + 1] += dp[i][j] / 2;
        }
      }
    }

    for (int i = 0; i < H; i++)
    {
      for (int j = 0; j < W; j++)
      {
        if (grid[i][j])
        {
          if (dp[i][j] % 2 == 0)
          {
            nGrid[i][j] = 1;
          }
          else
          {
            nGrid[i][j] = 0;
          }
        }
        else
        {
          if (dp[i][j] % 2 == 0)
          {
            nGrid[i][j] = 0;
          }
          else
          {
            nGrid[i][j] = 1;
          }
        }
      }
    }

    int nowy = 0, nowx = 0;
    while (0 <= nowy && nowy < H && 0 <= nowx && nowx < W)
    {
      if (nGrid[nowy][nowx])
        nowx++;
      else
        nowy++;
    }

    cout << nowy + 1 << " " << nowx + 1 << endl;
  }
  return 0;
}

// N回目の「南」「東」を決めなければならない
// 1～(N - 1)回目にたどりついた場所を知る必要はない．　また詳しいルートを1回ずつ区別して計算する必要もない．なぜならばN回目のルートやたどりつく場所に影響を与えないからであり各交差点を1～(N- 1)回目で何回通ったかが重要になる．まず，交差点(1, 1)をN-1回通る．この後，(1, 1)が東ならば(1, 2)を切り上げの(N - 1)/2回，南ならば(N - 1)/2回通る．同様に(1, 1)が東ならば(2, 1)を(N- 1)/2回，南ならば切上げの(N - 1)/2回通る．整理すると，
// (y, x)をT回通る時，
// (y, x)が東ならば(y, x + 1)を切り上げのT / 2回，(y + 1, x)をT / 2回通る．(y, x)が南ならば(y, x + 1)をT / 2回，(y + 1, x)を切り上げのT / 2回通る．
