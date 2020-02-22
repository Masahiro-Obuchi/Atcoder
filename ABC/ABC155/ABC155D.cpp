#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = (long long)(1e18) + 1;

int main()
{
  int N;
  long long K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];
  sort(A.begin(), A.end());
  long long l = -INF, r = INF;
  while (l + 1 < r)
  {
    long long x = (l + r) / 2;
    // ラムダ式 &を入れとくと関数の外にアクセス出来る
    bool ok = [&] {
      long long tot = 0;
      for (int i = 0; i < N; i++)
      {
        if (A[i] < 0)
        {
          int l = -1;
          r = N;
          while (l + 1 < r)
          {
            int c = (l + r) / 2;
            if (A[c] * A[i] < x)
              r = c; // ok側を動かす
            else
              l = c;
          }
          tot += N - r; // ある場所より右
        }
        else
        {
          int l = -1;
          r = N; // lはok rはng
          while (l + 1 < r)
          {
            int c = (l + r) / 2;
            if (A[c] * A[i] < x)
              l = c;
            else
              r = c;
          }
          tot += r; // 0-indexedだから
        }
        if (A[i] * A[i] < x)
          tot--;
      }
      tot /= 2;
      return tot < K;
    }(); // 定義の直後に関数呼び出し
    if (ok)
      l = x;
    else
      r = x;
  }
  cout << l << endl;
  return 0;
}

// 二分探索
// K番目の値 -> 「x未満がK個未満」である x の最大値　これは二分探索で求められる
// -INF : OK ... INF : NG x未満が何個あるか
// 相方を求める場面で重複するものが出てきてしまうが自分自身を引いて / 2をすればよい　どこが境界になるかを二分探索で見つける
// 答えを求めるための二分探索と相方を求めるための二分探索
