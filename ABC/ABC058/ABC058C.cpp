#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<string> S(N);
  vector<int> num(26);
  for (int i = 0; i < N; i++)
  {
    cin >> S[i];
  }
  for (int i = 0; i < S[0].size(); i++)
  {
    num[S[0][i] - 97]++;
  }
  for (int i = 1; i < N; i++)
  {
    vector<int> cnt(26);
    for (int j = 0; j < S[i].size(); j++)
    {
      cnt[S[i][j] - 97]++;
    }
    for (int k = 0; k < 26; k++)
    {
      num[k] = min(num[k], cnt[k]);
    }
  }
  vector<char> ans;
  for (int i = 0; i < 26; i++)
  {
    while (num[i] > 0)
    {
      ans.push_back(i + 97);
      num[i]--;
    }
  }
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i];
  }
  cout << endl;
}
