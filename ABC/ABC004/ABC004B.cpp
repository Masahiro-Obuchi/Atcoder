#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  vector<vector<char>> data(4, vector<char>(4));
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cin >> data[i][j];
    }
  }
  vector<vector<char>> res(4, vector<char>(4));
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      res[i][j] = data[3 - i][3 - j];
    }
  }
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}
