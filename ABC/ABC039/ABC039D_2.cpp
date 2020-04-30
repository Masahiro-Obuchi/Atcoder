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
  vector<vector<char>> img_original(H, vector<char>(W));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> img_original[i][j];
    }
  }
  vector<vector<char>> ans(H, vector<char>(W, '#'));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (img_original[i][j] == '.')
      {
        ans[i][j] = '.';
        for (int k = 0; k < 8; k++)
        {
          int ni = i + dy[k], nj = j + dx[k];
          if (ni >= 0 && ni < H && nj >= 0 && nj < W)
            ans[ni][nj] = '.';
        }
      }
    }
  }
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cerr << ans[i][j];
    }
    cerr << endl;
  }
  vector<vector<char>> dist(H, vector<char>(W, '.'));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (ans[i][j] == '#')
      {
        dist[i][j] = '#';
        for (int k = 0; k < 8; k++)
        {
          int ni = i + dy[k], nj = j + dx[k];
          if (ni >= 0 && ni < H && nj >= 0 && nj < W)
            dist[ni][nj] = '#';
        }
      }
    }
  }
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cerr << dist[i][j];
    }
    cerr << endl;
  }
  if (img_original == dist)
  {
    cout << "possible" << endl;
    for (int i = 0; i < H; i++)
    {
      for (int j = 0; j < W; j++)
      {
        cout << ans[i][j];
      }
      cout << endl;
    }
  }
  else
    cout << "impossible" << endl;
  return 0;
}

// まず白い画素があったらその画素と8近傍は縮小前は必ず白い画素であったことが分かる．（問題文の定義から，そうでないとその画素は黒くなってしまうから）すると，これ以外の画素を白くする理由はないため残りの画素は全部黒くしてしまっていいことが分かる．
// これにより縮小前の画像を生成し，それに実際に収縮処理を行い，それが処理後と等しければそれが答えとなる．そして等しくなかったら答えはimpossible
