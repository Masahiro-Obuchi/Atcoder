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

long long rec(int n, ll x)
{
  if (n == 0)
    return 1;
  ll len = (1LL << (n + 1)) - 3; // レベルn-1のバーガーの層数
  ll num = (1LL << n) - 1;       // レベルn-1のパティの数
  if (x == 1)
    return 0;
  else if (x <= len + 1)
    return rec(n - 1, x - 1); // 一番下のパン + その上のレベルN - 1バーガーの下からx - 1層
  else if (x == len + 2)
    return num + 1; // 一番下のパン + その上のレベルN - 1バーガー + その上のパティ
  else if (x <= (len + 1) * 2)
    return num + 1 + rec(n - 1, x - (len + 2)); // 前のやつ + その上のレベルN - 1バーガーの下からX - (len + 2)層
  else
    return num * 2 + 1; // 全て
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  ll X;
  cin >> N >> X;
  cout << rec(N, X) << endl;
  return 0;
}

// 再帰関数
// 再帰関数を適切に設計できるかという問題　バーガーの長さとパティの数がいくつになるかを予め計算しておく
// 今回の問題はrec(int n, ll x)　レベルがnのバーガーの下からx枚に含まれるパティの量とするとxの値に応じて，レベルがn-1のバーガーに関する問題に投げることが出来る．
