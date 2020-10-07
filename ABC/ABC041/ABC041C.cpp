#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  map<int, long long int> mp;
  for (int i = 0; i < N; i++)
  {
    long long int a;
    cin >> a;
    mp[a] = i;
  }
  vector<long long int> ans;
  for (auto itr = mp.begin(); itr != mp.end(); itr++)
  {
    ans.push_back(itr->second + 1);
  }
  for (int i = N - 1; i >= 0; i--)
  {
    cout << ans[i] << endl;
  }
}

// pairを使ってaiの降順にソート，sortにgreaterを渡す．また(-ai, i)の列を昇順にソートする．このようなやり方の方がいい．
