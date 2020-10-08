#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W, K;
  cin >> H >> W >> K;
  vector<vector<char>> cake(H, vector<char>(W));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> cake[i][j];
    }
  }
  vector<vector<int>> ans(H, vector<int>(W));
  int cnt = 1;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (cake[i][j] == '#')
      {
        ans[i][j] = cnt;
        cnt++;
      }
    }
  }
  for (int i = 0; i < H; i++)
  {
    for (int j = 1; j < W; j++)
    {
      if (ans[i][j] == 0)
      {
        ans[i][j] = ans[i][j - 1];
      }
    }
  }
  for (int i = 0; i < H; i++)
  {
    for (int j = W - 2; j >= 0; j--)
    {
      if (ans[i][j] == 0)
      {
        ans[i][j] = ans[i][j + 1];
      }
    }
  }
  for (int i = 1; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (ans[i][j] == 0)
      {
        ans[i][j] = ans[i - 1][j];
      }
    }
  }
  for (int i = H - 2; i >= 0; i--)
  {
    for (int j = 0; j < W; j++)
    {
      if (ans[i][j] == 0)
      {
        ans[i][j] = ans[i + 1][j];
      }
    }
  }
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
    cout << endl;
  }
}

// ほとんど行ごとに作るだけである．空行だけが問題であるが，これは上下の行から引き継いで来ればよい．
// 1. まずいちごに番号をつける．2. 左から右順に自身が0だったら左の値を採用を繰り返す．3. 右から左順に自身が0だったら右の値を採用を繰り返す．4. 上から下に向かって同じことを繰り返す．5. 下から上に向かって同じことを繰り返す．6. 完成
