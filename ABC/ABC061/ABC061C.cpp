#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int N, K;
  cin >> N >> K;
  map<long long int, long long int> mp;
  for (int i = 0; i < N; i++)
  {
    long long int a, b;
    cin >> a >> b;
    mp[a] += b;
  }
  long long int cnt = 0;
  long long int ans = 0;
  for (auto itr = mp.begin(); itr != mp.end(); itr++)
  {
    cnt += itr->second;
    if (cnt >= K)
    {
      ans = itr->first;
      break;
    }
  }
  cout << ans << endl;
}
