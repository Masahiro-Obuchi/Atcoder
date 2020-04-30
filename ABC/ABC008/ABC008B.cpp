#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  map<string, int> mp;
  for (int i = 0; i < N; i++)
  {
    string S;
    cin >> S;
    mp[S]++;
  }
  string ans;
  int tmp = 0;
  for (auto itr = mp.begin(); itr != mp.end(); itr++)
  {
    if (itr->second > tmp)
    {
      ans = itr->first;
      tmp = itr->second;
    }
  }
  cout << ans << endl;
}
