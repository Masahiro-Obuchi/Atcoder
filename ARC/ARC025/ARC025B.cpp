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

// Graph
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
// using Graph = vector<vector<int>>;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W;
  cin >> H >> W;
  vector<vector<int>> C(H, vector<int>(W));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      int c;
      cin >> c;
      if ((i % 2 == 0 && j % 2 != 0) || (i % 2 != 0 && j % 2 == 0))
        c *= -1;
      C[i][j] = c;
    }
  }

  // 二次元累積和の構築
  vector<vector<int>> s(H + 1, vector<int>(W + 1));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + C[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i <= H; i++)
  {
    for (int j = 0; j <= W; j++)
    {
      for (int k = 0; k <= H; k++)
      {
        for (int l = 0; l <= W; l++)
        {
          int tmp = s[k][l] - s[i][l] - s[k][j] + s[i][j];
          if (tmp == 0)
            ans = max(ans, abs(k - i) * abs(l - j));
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

// 黒チョコと白チョコを分離させるか白チョコの正負を反転させる．そして2次元累積和
