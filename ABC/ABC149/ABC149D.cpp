#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int N, K;
  cin >> N >> K;
  long long int R, S, P;
  cin >> R >> S >> P;
  string T;
  cin >> T;
  long long int ans = 0;
  vector<char> hand(N);
  for (int i = 0; i < N; i++)
  {
    if (i < K)
    {
      if (T[i] == 'r')
      {
        ans += P;
        hand[i] = 'p';
      }
      else if (T[i] == 's')
      {
        ans += R;
        hand[i] = 'r';
      }
      else
      {
        ans += S;
        hand[i] = 's';
      }
    }
    else
    {
      if (T[i] == 'r' && hand[i - K] != 'p')
      {
        ans += P;
        hand[i] = 'p';
      }
      else if (T[i] == 's' && hand[i - K] != 'r')
      {
        ans += R;
        hand[i] = 'r';
      }
      else if (T[i] == 'p' && hand[i - K] != 's')
      {
        ans += S;
        hand[i] = 's';
      }
      else
      {
        hand[i] = 'x';
      }
    }
  }
  cout << ans << endl;
}

// まず前提として，a回目にこちらが出す手とb回目にこちらが出す手は，a mod K != b mod K ならば独立である．N回のじゃんけんを,mod KによってK個のグループに分けることを考える．この時，各グループに対して，以下のsub問題を考えることが出来れば，この問題を解くことが出来る．
// sub問題　このグループに属するじゃんけんで，最大何点取れるか，ただし，連続で同じ手を出すことは出来ない
// 各グループごとに貪欲，or DP
