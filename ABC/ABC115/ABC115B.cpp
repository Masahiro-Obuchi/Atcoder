#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> p(N);
  for (int i = 0; i < N; i++)
  {
    cin >> p.at(i);
  }
  sort(p.begin(), p.end(), greater<int>());
  int ans = p.at(0) / 2;
  for (int i = 1; i < N; i++)
  {
    ans += p.at(i);
  }
  cout << ans << endl;
  return 0;
}
