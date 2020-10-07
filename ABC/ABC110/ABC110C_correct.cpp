#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S, T;
  cin >> S >> T;
  bool ok = true;
  map<char, char> ma, ima;
  for (int i = 0; i < S.size(); i++)
  {
    char s = S.at(i), t = T.at(i);
    if (ma.count(s) > 0) // ma に s が存在している
      if (ma[s] != t)    //ma の キーsの値がtではない
        ok = false;
    if (ima.count(t) > 0) // imaにtが存在している
      if (ima[t] != s)    // imaのキーtの値がsではない
        ok = false;
    ma[s] = t;  //maのキーsに値tをセット
    ima[t] = s; // imaのキーTに値sをセット
  }
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
