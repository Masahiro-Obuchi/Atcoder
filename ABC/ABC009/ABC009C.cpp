#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, K;
  string S;
  cin >> N >> K >> S;
  string T;
  string U = S;
  sort(U.begin(), U.end());
  vector<int> used(N, 0);
  for (int i = 0; i < N - 1; i++)
  { // i文字目を残ったものから確定させる
    for (int j = 0; j < N; j++)
    {
      if (used[j] == 0)
      {
        string tmp = T + U[j]; // j文字目が残っているとき
        int num1 = 0, num2 = 0;
        for (int l = 0; l < i + 1; l++)
        {
          if (tmp[l] != S[l])
            num1++;
        }
        vector<int> a(30, 0), b(30, 0);
        for (int l = 0; l < N; l++)
        {
          if (l != j && used[l] == 0)
            a[U[l] - 'a']++;
        }
        for (int l = i + 1; l < N; l++)
        { // i文字目以降
          b[S[l] - 'a']++;
        }
        for (int l = 0; l < 30; l++)
        {
          num2 += min(a[l], b[l]);
        }
        if (num1 + N - i - 1 - num2 <= K)
        {
          used[j]++;
          T += U[j];
          break;
        }
      }
    }
  }
  for (int i = 0; i < N; i++)
  {
    if (used[i] == 0)
      T += U[i];
  }
  cout << T << endl;
}

// https://www.slideshare.net/chokudai/abc009 参考
// まだ使える文字を小さい順に
// T + cにして大丈夫なら
