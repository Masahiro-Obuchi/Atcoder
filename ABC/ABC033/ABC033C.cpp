#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  string S;
  cin >> S;
  int ans = 0;
  bool existZero;
  if (S[0] != '0')
    existZero = false;
  else
    existZero = true;
  for (int i = 1; i < S.size(); i++)
  {
    if (i % 2 != 0)
    {
      if (S[i] == '+')
      {
        if (!existZero)
        {
          ans++;
        }
        existZero = false;
      }
    }
    else
    {
      if (S[i] == '0')
        existZero = true;
    }
  }
  if (!existZero)
    ans++;
  cout << ans << endl;
}

// +が出るまで逐次計算
// +で区切る　区切ったそれぞれの部分に対して，初期状態で0が1つもなければ，1回書き換えが必要．この合計が必要な最小個数となる
