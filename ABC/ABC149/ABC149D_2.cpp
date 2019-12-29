#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int N, K;
  cin >> N >> K;
  long long int R, S, P;
  cin >> R >> S >> P;
  string T;
  cin >> T;
  long long int ans = 0;
  vector<vector<char>> group(K);
  for (int i = 0; i < N; i++)
  {
    group[i % K].push_back(T[i]);
  }
  for (int i = 0; i < K; i++)
  {
    for (int j = 0; j < group[i].size(); i++)
    {
      if (j == 0)
      {
        if (group[i][j] == 'r')
        {
          ans += P;
        }
        else if (group[i][j] == 's')
        {
          ans += R;
        }
        else if (group[i][j] == 'p')
        {
          ans += S;
        }
      }
      else
      {
        if (group[i][j] == 'r' && group[i][j - 1] != 'r')
        {
          ans += P;
        }
        else if (group[i][j] == 's' && group[i][j - 1] != 's')
        {
          ans += R;
        }
        else if (group[i][j] == 'p' && group[i][j - 1] != 'p')
        {
          ans += S;
        }
        else
          continue;
      }
    }
  }
  cout << ans << endl;
}
