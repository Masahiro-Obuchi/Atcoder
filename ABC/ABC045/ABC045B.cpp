#include <bits/stdc++.h>
using namespace std;

int main()
{
  string sa, sb, sc;
  char now;
  int status; // 誰のターンか
  cin >> sa >> sb >> sc;
  now = sa[0];
  sa = sa.erase(0, 1);
  while (true)
  {
    if (now == 'a')
    {
      now = sa[0];
      sa = sa.erase(0, 1);
      status = 0;
    }
    else if (now == 'b')
    {
      now = sb[0];
      sb = sb.erase(0, 1);
      status = 1;
    }
    else if (now == 'c')
    {
      now = sc[0];
      sc = sc.erase(0, 1);
      status = 2;
    }
    else if (sa == "" or sb == "" or sc == "")
    {
      break;
    }
  }
  if (status == 0)
    cout << "A" << endl;
  if (status == 1)
    cout << "B" << endl;
  if (status == 2)
    cout << "C" << endl;
}

// ルールの通りにシミュレーションを行う．実装の方針としては，3人それぞれのカードの列をstringなどで文字列にして持って置き，現在その文字列のうち何番目の文字がその人の持っているカードのうち先頭にあるかを変数に持つ．また，現在誰のターンであるかを表す変数も持って置く．
// それぞれのターンにおいては，まずそのターンの人がカードを使い切ったかを確認し，そうでないならば自分のカードの位置を表すカウントを1増やしてから，文字に対応する人のターンに移動する．
