#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  map<char, int> mp;
  for (int i = 0; i < S.size(); i++)
  {
    mp[S[i]]++;
  }
  bool can = true;
  for (auto itr = mp.begin(); itr != mp.end(); itr++)
  {
    if (itr->second > 1)
    {
      can = false;
      break;
    }
  }
  if (can)
    cout << "yes" << endl;
  else
    cout << "no" << endl;
}

// mapが使えそうな問題
