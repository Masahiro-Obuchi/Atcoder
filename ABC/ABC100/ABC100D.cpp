#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<vector<long long int>> data(N, vector<long long int>(3));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> data.at(i).at(j);
    }
  }
  long long ans = -1;
  //求めるのは絶対値の合計ではなく合計の絶対値
  //どの要素を正，負どちらの方向に最大化させるかで8通り
  for (int bit = 0; bit < (1 << 3); bit++)
  {
    vector<long long int> svec(N);
    for (int j = 0; j < N; j++)
    {
      long long int S = 0;
      for (int k = 0; k < 3; k++)
      {
        if (1 & (bit >> k))
        { //bitにk番目のフラグが立っているか
          svec.at(j) += data.at(j).at(k);
        }
        else
        {
          svec.at(j) -= data.at(j).at(k);
        }
      }
    }
    sort(svec.begin(), svec.end(), greater<long long int>());
    long long int sum = 0;
    for (int j = 0; j < M; j++)
    {
      sum += svec.at(j);
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
