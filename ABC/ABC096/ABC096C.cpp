#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;

  vector<string> svec(H);

  for (int i = 0; i < H; i++)
  {
    cin >> svec.at(i);
  }

  const int dx[4] = {0, -1, 1, 0};
  const int dy[4] = {-1, 0, 0, 1};

  bool answer = true;

  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (svec.at(i).at(j) == '.')
      {
        continue;
      }
      bool exist = false;
      for (int d = 0; d < 4; d++)
      {
        const int ni = i + dx[d];
        const int nj = j + dy[d];

        if (ni < 0 || ni >= H)
        {
          continue;
        }
        if (nj < 0 || nj >= W)
        {
          continue;
        }
        if (svec.at(ni).at(nj) == '#')
        {
          exist = true;
        }
      }
      if (!exist)
      {
        answer = false;
        break;
      }
    }
  }
  if (answer)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}
