#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
/*
struct Edge
{
    int to;
    ll weight;
    Edge(int t, ll w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
*/
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int H;
  while (true)
  {
    cin >> H;
    if (H == 0)
      break;

    vector<vector<int>> block(H, vector<int>(5));
    for (int i = 0; i < H; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        cin >> block[i][j];
      }
    }

    int ans = 0;
    while (true)
    {
      int add = 0;
      for (int i = 0; i < H; i++)
      {
        int cnt = 1;
        int num = 0;
        for (int j = 1; j < 5; j++)
        {
          if (block[i][j] != -1 && block[i][j] == block[i][j - 1])
            cnt++;
          else
          {
            if (cnt >= 3)
            {
              num = block[i][j - 1];
            }
            cnt = 1;
          }
        }
        if (cnt >= 3)
          num = block[i][4];
        vector<int> idx;
        for (int j = 0; j < 5; j++)
        {
          if (j == 0)
          {
            if (block[i][j] == num && block[i][j] == block[i][j + 1])
              idx.push_back(j);
          }
          else if (j == 4)
          {
            if (block[i][j] == num && block[i][j] == block[i][j - 1])
              idx.push_back(j);
          }
          else
          {
            if (block[i][j] == num && (block[i][j] == block[i][j - 1] || block[i][j] == block[i][j + 1]))
              idx.push_back(j);
          }
        }
        for (auto it : idx)
        {
          add += block[i][it];
          block[i][it] = 0;
        }
      }

      ans += add;
      for (int i = 0; i < H; i++)
      {
        for (int j = 0; j < 5; j++)
        {
          if (block[i][j] == 0)
          {
            for (int row = i; row >= 0; row--)
            {
              if (row == 0)
              {
                block[row][j] = -1;
              }
              else
              {
                block[row][j] = block[row - 1][j];
              }
            }
          }
        }
      }

      if (add == 0)
        break;
    }
    cout << ans << endl;
  }
  return 0;
}
