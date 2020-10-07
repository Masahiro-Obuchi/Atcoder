#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> T(N);
  for (int i = 0; i < N; i++)
  {
    cin >> T.at(i);
  }
  int M;
  cin >> M;
  vector<vector<int>> data(M, vector<int>(2));
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cin >> data.at(i).at(j);
    }
  }
  for (int i = 0; i < M; i++)
  {
    long long int sum = accumulate(T.begin(), T.end(), 0);
    sum -= T.at(data.at(i).at(0) - 1);
    sum += data.at(i).at(1);
    cout << sum << endl;
  }
}
