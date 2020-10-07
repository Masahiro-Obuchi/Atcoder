#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S, T;
  cin >> S >> T;
  bool ok = false;
  int tpos = -1;
  vector<string> ans;
  if (T.size() > S.size())
    cout << "UNRESTORABLE" << endl;
  else
  {
    for (int i = 0; i <= S.size() - T.size(); i++)
    {
      if (S[i] == '?' or S[i] == T[0])
      {
        tpos = i;
        bool ok2 = true;
        for (int j = 1; j < T.size(); j++)
        {
          if (i + j >= S.size())
          {
            ok2 = false;
            break;
          }
          else
          {
            if (T[j] == S[i + j] or S[i + j] == '?')
            {
              continue;
            }
            else
            {
              ok2 = false;
              break;
            }
          }
        }
        if (ok2)
        {
          ok = true;
        }
      }
    }
    if (ok)
    {
      for (int i = tpos; i < tpos + T.size(); i++)
      {
        S[i] = T[i - tpos];
      }
      for (int i = 0; i < S.size(); i++)
      {
        if (S[i] == '?')
          S[i] = 'a';
      }
      cout << S << endl;
    }
    else
    {
      cout << "UNRESTORABLE" << endl;
    }
  }
}

// 「Tを配置できる最も後ろの位置に配置して残りをaで埋める」だと嘘で、すべて試して最小を取る必要がある。
