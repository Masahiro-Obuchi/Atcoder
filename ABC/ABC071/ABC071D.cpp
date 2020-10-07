#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<string> S(2);
  for (int i = 0; i < 2; i++)
    cin >> S[i];

  ll ans = 1;

  for (int j = 0; j < N; j++)
  {
    if (S[0][j] == S[1][j])
    {
      if (j == 0)
      {
        ans *= 3;
        ans %= MOD;
      }
      else
      {
        // 左2文字が等しいときと異なるとき (XとY)
        if (S[0][j - 1] == S[1][j - 1])
        { // Xの場合
          ans *= 2;
          ans %= MOD;
        }
        else
        { // Yの場合
          continue;
        }
      }
    }
    else if (j + 1 < N && S[0][j] == S[0][j + 1])
    {
      if (j == 0)
      {
        ans *= 3;
        ans %= MOD;
        ans *= 2;
        ans %= MOD;
        j++;
      }
      else
      {
        // 左2文字が等しいときと異なるとき(XとY)
        if (S[0][j - 1] == S[1][j - 1])
        { // Xの場合
          ans *= 2;
          ans %= MOD;
          j++;
        }
        else
        { // Yの場合
          ans *= 3;
          ans %= MOD;
          j++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

// 横2つが縦に2つ連なる場合が横に2つ連なる場合の不足
// ↑の場合に色の組み合わせがどうなるのかをしっかり実験する
// 縦2×横1をX，縦1×横2をYとする．一番左の箇所についてはX: 3, Y: 6通り．
// それ以外の場所についてはそれより左の箇所が全て塗られているとき，X(すぐ隣がX): 2通り，X(すぐ隣がY): 1通り，Y(すぐ隣がX): 2通り，Y(すぐ隣がY): 3通り　(解説参照)
