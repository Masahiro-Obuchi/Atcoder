#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  string S;
  cin >> S;
  int N;
  N = S.size();
  vector<int> ans(N);

  // Rグループについて
  int cnt = 0;
  int evenNum = 0, oddNum = 0;
  for (int i = 0; i < N; i++)
  {
    if (S[i] == 'R')
      cnt++;
    else
    {
      evenNum = cnt / 2;
      oddNum = cnt - evenNum;
      ans[i] += evenNum;
      ans[i - 1] += oddNum;
      cnt = 0, evenNum = 0, oddNum = 0;
    }
  }

  // Lグループについて
  cnt = 0;
  evenNum = 0, oddNum = 0;
  for (int i = N - 1; i >= 0; i--)
  {
    if (S[i] == 'L')
      cnt++;
    else
    {
      evenNum = cnt / 2;
      oddNum = cnt - evenNum;
      ans[i] += evenNum;
      ans[i + 1] += oddNum;
      cnt = 0, evenNum = 0, oddNum = 0;
    }
  }

  for (int i = 0; i < N; i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
}

// 偶数回数後 R->L L->R 各マスの偶奇に着目する 折り返し地点　(Rから見たらL，Lから見たらR)までの距離が偶数か奇数かで場合を分けることができる．偶数回後の移動では偶数距離離れたもの折り返し地点に収束し，奇数距離離れたものは折り返し地点の一つ前に収束する．折り返し地点までの距離が偶数の人はevenNum = cnt / 2(切り捨て), 奇数の人はoddNum = (cnt + 1)/2で求められる．（切り上げ）（図を書けばわかる．）
