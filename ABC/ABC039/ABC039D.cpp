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
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (auto &it : S)
    cin >> it;
  vector<vector<char>> img(H, vector<char>(W, '.'));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (S[i][j] == '#')
      {
        int cnt = 0;
        for (int k = 0; k < 8; k++)
        {
          int ni = i + dy[k], nj = j + dx[k];
          if (ni < 0 || ni >= H || nj < 0 || nj >= W || (ni >= 0 && ni < H && nj >= 0 && nj < W && S[ni][nj] == '#'))
            cnt++;
        }
        if (cnt == 8)
          img[i][j] = '#';
      }
    }
  }
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cerr << img[i][j];
    }
    cerr << endl;
  }
  vector<vector<char>> img2(H, vector<char>(W, '.'));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (img[i][j] == '#')
      {
        img2[i][j] = '#';
        for (int k = 0; k < 8; k++)
        {
          int ni = i + dy[k], nj = j + dx[k];
          if (ni >= 0 && ni < H && nj >= 0 && nj < W)
            img2[ni][nj] = '#';
        }
      }
    }
  }
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cerr << img2[i][j];
    }
    cerr << endl;
  }
  bool can = true;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (S[i][j] != img2[i][j])
        can = false;
    }
  }
  if (can)
  {
    cout << "possible" << endl;
    for (int i = 0; i < H; i++)
    {
      for (int j = 0; j < W; j++)
      {
        cout << img[i][j];
      }
      cout << endl;
    }
  }
  else
    cout << "impossible" << endl;
  return 0;
}

// まず収縮後の画像を作ってみて逆の操作をした後に一致しなかったらNG
