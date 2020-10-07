#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S, T;
  cin >> S >> T;
  vector<string> ans;
  if (T.size() > S.size())
    cout << "UNRESTORABLE" << endl;
  else
  {
    for (int i = 0; i <= S.size() - T.size(); i++)
    {
      bool ok = true;
      for (int j = 0; j < T.size(); j++)
      {
        if (S[i + j] != '?' and S[i + j] != T[j])
          ok = false;
      }
      if (ok)
      {
        string tmp;
        for (int j = 0; j < S.size(); j++)
          tmp += S[j];
        for (int j = 0; j < T.size(); j++)
          tmp[i + j] = T[j];
        for (int j = 0; j < S.size(); j++)
        {
          if (tmp[j] == '?')
            tmp[j] = 'a';
        }
        ans.push_back(tmp);
      }
    }
    sort(ans.begin(), ans.end());
    if (ans.size() == 0)
      cout << "UNRESTORABLE" << endl;
    else
      cout << ans[0] << endl;
  }
}

// 「Tを配置できる最も後ろの位置に配置して残りをaで埋める」だと嘘で、すべて試して最小を取る必要がある。
