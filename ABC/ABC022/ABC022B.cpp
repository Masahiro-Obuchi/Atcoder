#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  int ans = 0;
  map<int, int> mp;
  for (int i = N - 1; i >= 0; i--)
  {
    mp[A[i]]++;
  }
  for (auto itr = mp.begin(); itr != mp.end(); itr++)
  {
    if (itr->second >= 2)
    {
      ans += itr->second - 1;
    }
  }
  cout << ans << endl;
}
