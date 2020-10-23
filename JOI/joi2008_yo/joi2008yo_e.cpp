#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int R, C;
  cin >> R >> C;
  vector<vector<int>> senbei(R, vector<int>(C));
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      cin >> senbei[i][j];
    }
  }
  int ans = 0;
  for (int bit = 0; bit < (1 << R); bit++)
  {
    int sum = 0;
    for (int j = 0; j < C; j++)
    {
      int d = 0;
      for (int i = 0; i < R; i++)
      { // 裏になっているせんべいの枚数を数える
        if (bit & (1 << i))
          d += senbei[i][j] == 1;
        else
          d += senbei[i][j] == 0;
      }
      sum += max(d, R - d);
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}

// ヒントR << C, 横の何行を裏返すかをbit全探索する．
// 縦はシンプルに表の方が多ければ裏返す．
