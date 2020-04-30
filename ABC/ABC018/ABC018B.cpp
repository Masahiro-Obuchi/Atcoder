#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  int N;
  cin >> S >> N;
  vector<vector<int>> data(N, vector<int>(2));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cin >> data[i][j];
    }
  }
  for (int i = 0; i < N; i++)
  {
    string substr;
    substr = S.substr(data[i][0] - 1, data[i][1] - data[i][0] + 1);
    reverse(substr.begin(), substr.end());
    for (int j = data[i][0] - 1; j < data[i][1]; j++)
    {
      S[j] = substr[j - data[i][0] + 1];
    }
  }
  cout << S << endl;
}
