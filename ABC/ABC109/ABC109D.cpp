#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

struct ope
{
  /* data */
  int y1;
  int x1;
  int y2;
  int x2;
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W;
  cin >> H >> W;
  vector<vector<int>> a(H, vector<int>(W));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> a[i][j];
    }
  }
  vector<ope> o;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W - 1; j++)
    {
      if (a[i][j] % 2 != 0)
      {
        a[i][j]--;
        a[i][j + 1]++;
        o.push_back({i, j, i, j + 1});
      }
    }
  }
  for (int i = 0; i < H - 1; i++)
  {
    if (a[i][W - 1] % 2 != 0)
    {
      a[i][W - 1]--;
      a[i + 1][W - 1]++;
      o.push_back({i, W - 1, i + 1, W - 1});
    }
  }
  cout << o.size() << endl;
  for (auto &it : o)
    cout << it.y1 + 1 << " " << it.x1 + 1 << " " << it.y2 + 1 << " " << it.x2 + 1 << endl;
  int cnt = 0;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (a[i][j] % 2 == 0)
        cnt++;
    }
  }
  cerr << cnt << endl;
  return 0;
}

// 配列が0-indexedであることを忘れて1WA
// 奇数のやつを全部右にやる操作を上から下までやった後に一番右の列において奇数のやつを全部上から下まで送る
