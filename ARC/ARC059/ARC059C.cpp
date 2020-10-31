#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++)
  {
    cin >> a.at(i);
  }
  int ans = 400000000;
  for (int i = -100; i <= 100; i++)
  {
    int sum = 0;
    for (int j = 0; j < N; j++)
    {
      int cost = pow(abs(i - a.at(j)), 2);
      sum += cost;
    }
    ans = min(sum, ans);
  }
  cout << ans << endl;
}
