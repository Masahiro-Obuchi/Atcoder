#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  long int H;
  int CX, CY;

  vector<vector<int>> data(N, vector<int>(3));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> data.at(i).at(j);
    }
  }

  bool can = false;
  for (CX = 0; CX <= 100; CX++)
  {
    for (CY = 0; CY <= 100; CY++)
    {
      for (int i = 0; i < N; i++)
      {
        if (data.at(i).at(2) == 0)
        {
          continue;
        }
        else
        {
          H = data.at(i).at(2) + abs(data.at(i).at(0) - CX) + abs(data.at(i).at(1) - CY);
          bool can2 = true;
          for (int j = 0; j < N; j++)
          {
            if (data.at(j).at(2) != H - abs(data.at(j).at(0) - CX) - abs(data.at(j).at(1) - CY))
              can2 = false;
            else
              continue;
            if (!can2)
              break;
          }
          if (can2)
            can = true;
        }
      }
      if (can)
        break;
    }
    if (can)
      break;
  }
  cout << CX << " " << CY << " " << H << endl;
  return 0;
}
