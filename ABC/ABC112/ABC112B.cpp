#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, T;
  cin >> N >> T;
  vector<vector<int>> data(N, vector<int>(2));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cin >> data[i][j];
    }
  }
  bool tle = true;
  for (int i = 0; i < N; i++)
  {
    if (data[i][1] <= T)
      tle = false;
  }
  int ans = 10000;
  for (int i = 0; i < N; i++)
  {
    if (data[i][1] <= T)
    {
      ans = min(ans, data[i][0]);
    }
  }
  if (tle)
    cout << "TLE" << endl;
  else
    cout << ans << endl;
  return 0;
}
