#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> data(Q, vector<int>(3));
  for (int i = 0; i < Q; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> data[i][j];
    }
  }
  vector<int> ans(N + 1);
  for (int i = 0; i < Q; i++)
  {
    for (int j = data[i][0]; j <= data[i][1]; j++)
    {
      ans[j] = data[i][2];
    }
  }
  for (int i = 1; i < N + 1; i++)
  {
    cout << ans[i] << endl;
  }
}
