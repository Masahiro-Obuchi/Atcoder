#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, D;
  cin >> N >> D;
  vector<vector<int>> X(N, vector<int>(D));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < D; j++)
    {
      cin >> X.at(i).at(j);
    }
  }
  int ans = 0;
  for (int i = 0; i < N - 1; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      int square_sum = 0;
      for (int k = 0; k < D; k++)
      {
        square_sum += pow((X.at(i).at(k) - X.at(j).at(k)), 2);
      }
      if (ceil(sqrt(square_sum)) == floor(sqrt(square_sum)))
        ans++;
    }
  }
  cout << ans << endl;
}
