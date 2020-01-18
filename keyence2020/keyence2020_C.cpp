
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main()
{
  long long N, K, S;
  cin >> N >> K >> S;
  vector<long long> ans;
  for (int i = 0; i < K; i++)
  {
    ans.push_back(S);
  }
  if (S < 100000000)
  {
    for (int i = 0; i < N - K; i++)
    {
      ans.push_back(S + 1);
    }
  }
  else
  {
    for (int i = 0; i < N - K; i++)
    {
      ans.push_back(S - 1);
    }
  }

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
}
