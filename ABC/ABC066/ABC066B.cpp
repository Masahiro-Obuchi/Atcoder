#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  S.pop_back();
  while (true)
  {
    bool ok = true;
    if (S.size() % 2 != 0)
    {
      S.pop_back();
      continue;
    }
    else
    {
      for (int i = 0; i < S.size() / 2; i++)
      {
        if (S[i] != S[i + S.size() / 2])
        {
          ok = false;
          break;
        }
      }
      if (ok)
        break;
      else
      {
        S.pop_back();
      }
    }
  }
  cout << S.size() << endl;
}

// 文字列の末尾を消したい場合はpop_back()を用いる
