#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

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
  int maxv = 0;
  for (auto itr = mp.begin(); itr != mp.end(); itr++)
  {
    maxv = max(maxv, itr->second);
  }
  for (auto itr = mp.begin(); itr != mp.end(); itr++)
  {
    if (itr->second == maxv)
      cout << itr->first << endl;
  }
}
