#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<vector<char>> data(N, vector<char>(N));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> data[i][j];
    }
  }
  vector<vector<char>> ans(N, vector<char>(N));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      ans[i][j] = data[N - 1 - j][i];
    }
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (j == N - 1)
        cout << ans[i][j] << endl;
      else
        cout << ans[i][j];
    }
  }
}

// ちゃんと紙に書いてi, jの対応関係をはっきりさせるといい，頭の中だけでこれらを考えるのは難しい
// マス目(i, j)は回転後マス目(j, N - 1 - i)の位置に移る
