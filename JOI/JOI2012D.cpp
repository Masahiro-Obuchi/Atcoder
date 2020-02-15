#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

const int MOD2 = 10000;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> A(N, -1);
  for (int i = 0; i < K; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    A[a] = b;
  }

  long long dp[110][3][3] = {0}; // i日目にj, i-1日目にkを食べる場合の数

  // dpテーブルの初期化
  for (int i = 0; i < 3; i++)
  {
    if (A[1] != -1 && i != A[1])
      continue;
    for (int j = 0; j < 3; j++)
    {
      if (A[0] != -1 && j != A[0])
        continue;
      dp[1][i][j] = 1;
    }
  }

  for (int i = 1; i < N; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (A[i + 1] != -1 && j != A[i + 1])
        continue;
      for (int k = 0; k < 3; k++)
      {
        for (int l = 0; l < 3; l++)
        {
          if (j == k && k == l) // 3日以上連続して同じパスタを食べることが出来ない
            continue;
          dp[i + 1][j][k] += dp[i][k][l] % 10000;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      ans += dp[N - 1][i][j] % 10000;
    }
  }

  ans %= 10000;
  cout << ans << endl;
}

// 1日目からi+1日目までのパスタが決まっていたとすると，i+2日目以降のパスタを決める際にはi日目とi+1日目のパスタの情報だけ用いられる．（今から見てどこまでの情報が用いられるのかに注意する）「i日目のパスタがAで，i+1日目のパスタがBだったときのi+2日目以降の予定の数をf(i, A, B)とすれば，f(i, A, B)はf(i+1, A', B')の組み合わせで書けることが分かる．全てのA', B'の組（全部で3 * 3 = 9通りある）に対してf(i+1, A', B')が計算できれば，f(i, A, B)が計算できる．
// 0-indexedにしているため出力する値はdp[N - 1][i][j]の総和
