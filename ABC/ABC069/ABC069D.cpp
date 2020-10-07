#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W;
  cin >> H >> W;
  int N;
  cin >> N;
  vector<int> a(N);
  for (auto &ai : a)
    cin >> ai;
  vector<vector<int>> grid(H, vector<int>(W));

  int now = 0;
  int rem = a[now];

  for (int i = 0; i < H; i++)
  {
    if (i % 2 == 0)
    {
      for (int j = 0; j < W; j++)
      {
        grid[i][j] = now + 1;
        rem--;
        if (rem == 0)
        {
          now++;
          rem = a[now];
        }
      }
    }
    else
    {
      for (int j = W - 1; j >= 0; j--)
      {
        grid[i][j] = now + 1;
        rem--;
        if (rem == 0)
        {
          now++;
          rem = a[now];
        }
      }
    }
  }
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
