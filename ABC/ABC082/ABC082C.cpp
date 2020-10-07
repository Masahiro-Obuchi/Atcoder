#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long int> a(N);
  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  long long int ans = 0;
  map<long long int, int> mp;
  for (int i = 0; i < N; i++)
  {
    mp[a[i]]++;
  }
  for (auto itr = mp.begin(); itr != mp.end(); itr++)
  {
    if (itr->first <= itr->second)
    {
      ans += itr->second - itr->first;
    }
    else
    {
      ans += itr->second;
    }
  }
  cout << ans << endl;
}
