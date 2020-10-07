#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> data[i][j];
    }
  }
  for (int i = 0; i < H + 2; i++)
  {
    for (int j = 0; j < W + 2; j++)
    {
      if (i == 0 or i == H + 1 or j == 0 or j == W + 1)
      {
        if (j == W + 1)
          cout << "#" << endl;
        else
          cout << "#";
      }
      else
      {
        cout << data[i - 1][j - 1];
      }
    }
  }
}
