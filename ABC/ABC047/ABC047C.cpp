#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  char now = S[0];
  int cnt = 0;
  for (int i = 1; i < S.size(); i++)
  {
    if (S[i] != S[i - 1])
    {
      cnt++;
      now = S[i];
    }
  }
  cout << cnt << endl;
}

// 結構時間がかかってしまったが，実験してみたら簡単だった．初めの文字をnowとして次に文字から見ていきnowと異なる場合はcntをインクリメントし，nowを更新する．ただそれだけ．
