#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> X(M);
  for (int i = 0; i < M; i++)
  {
    cin >> X.at(i);
  }
  int ans;
  if (M - N <= 0)
    ans = 0;
  else
  {
    sort(X.begin(), X.end());
    vector<int> diffs;
    for (int i = 1; i < X.size(); i++)
      diffs.push_back(X.at(i) - X.at(i - 1));
    sort(diffs.begin(), diffs.end(), greater<int>());
    ans = X.at(M - 1) - X.at(0);
    for (int i = 0; i < N - 1; i++)
    {
      ans -= diffs.at(i);
    }
  }
  cout << ans << endl;
  return 0;
}
