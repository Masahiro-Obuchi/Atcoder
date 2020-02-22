#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;
long long dp[1000005][2];

int main()
{
  string S;
  cin >> S;
  reverse(S.begin(), S.end()); // 下の桁がS[0]になって欲しい
  S += '0';                    // 1桁多めに払う場合があるため先頭（文字列だと最後）に0を追加
  int N = S.size();
  for (int i = 0; i < N + 1; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0; // 0桁決めた時は繰り下がりは0でそのときの答えは0
  for (int i = 0; i < N + 1; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      int x = S[0] - '0'; // Nのi桁目
      x += j;             // N に対応　引く数を+j(1か0)することで繰り下がりを表現　Aから1を引くのとNに1を足す（引かれる側から1を引くのと引く側に1を足すのは同じ）
      for (int a = 0; a < 10; a++)
      {                         // aを0～9のどれにするか10通りある
        int ni = i + 1, nj = 0; // 次の桁のiと繰り下がり　とりあえず繰り下がりは0で初期化
        int b = a - x;
        if (b < 0) // 繰り下がり
        {
          nj = 1;
          b += 10;
        }
        dp[ni][nj] = min(dp[ni][nj], dp[i][j] + a + b);
      }
    }
  }
  int ans = dp[N][0]; // n桁目で繰り下がりが残っていてはいけないためjは0にする
  cout << ans << endl;
  return 0;
}

// 桁DPの本質 1桁ずつ決めていくこと　状態として繰り下がりがあるかどうかだけを持っておけばよい
