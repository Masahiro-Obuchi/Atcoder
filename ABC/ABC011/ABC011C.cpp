#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int NG1, NG2, NG3;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N >> NG1 >> NG2 >> NG3;
  if (N == NG1 || N == NG2 || N == NG3)
    cout << "NO" << endl;
  else
  {
    int cnt = 0;
    while (N > 0)
    {
      if (N - 3 != NG1 && N - 3 != NG2 && N - 3 != NG3)
      {
        N -= 3;
        cnt++;
      }
      else if (N - 2 != NG1 && N - 2 != NG2 && N - 2 != NG3)
      {
        N -= 2;
        cnt++;
      }
      else if (N - 1 != NG1 && N - 1 != NG2 && N - 1 != NG3)
      {
        N -= 1;
        cnt++;
      }
      else
      {
        cout << "NO" << endl;
        return 0;
      }
    }
    if (cnt <= 100)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

// 全探索は3^100となり絶対に無理
// 動的計画法か貪欲法によって求める
// DP 数字kにたどりつくまでに最低何手必要か
// 貪欲法　そもそも3を引いても大丈夫な時に1や2を引く必要があるのか　よって引ける数のうち，最も大きいものを引いていけばよい
