#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v.at(i);
  }

  map<int, int> even, odd; //mapで各数列の要素の出現数を記録する

  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
      odd[v[i]]++; // キーvi(first)のときの値(second)をインクリメント
    else
      even[v[i]]++; // キーviのときの値をインクリメント
  }

  int even_1 = 0, even_2 = 0, odd_1 = 0, odd_2 = 0;
  int e1 = 0, e2 = 0, o1 = 0, o2 = 0;
  int cnt = 0;
  for (auto itr = even.begin(); itr != even.end(); ++itr)
  {
    if (itr->second > cnt)
    {
      cnt = itr->second;
      even_1 = itr->first;
    }
  }
  e1 = cnt;
  cnt = 0;
  for (auto itr = even.begin(); itr != even.end(); ++itr)
  {
    if (itr->second > cnt && itr->first != even_1) // 最も出現回数が大きいeven_1を除いた要素の中で最も出現回数が大きいものを求めている．
    {
      cnt = itr->second;
      even_2 = itr->first;
    }
  }
  e2 = cnt;

  cnt = 0;
  for (auto itr = odd.begin(); itr != odd.end(); ++itr)
  {
    if (itr->second > cnt)
    {
      cnt = itr->second;
      odd_1 = itr->first;
    }
  }
  o1 = cnt;
  cnt = 0;
  for (auto itr = odd.begin(); itr != odd.end(); ++itr)
  {
    if (itr->second > cnt && itr->first != odd_1)
    {
      cnt = itr->second;
      odd_2 = itr->first;
    }
  }
  o2 = cnt;

  if (even_1 == odd_1)
  {
    cout << min(n - e1 - o2, n - e2 - o1) << endl;
  }
  else
  {
    cout << n - e1 - o1 << endl;
  }

  return 0;
}
