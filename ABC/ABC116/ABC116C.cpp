#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> h(N);
  for (int i = 0; i < N; i++)
  {
    cin >> h[i];
  }

  //高さが0になるまでやる
  int res = 0;
  while (true)
  {
    //最高高さが0だったらおしまい
    if (*max_element(h.begin(), h.end()) == 0)
      break;

    //区間分割する
    int i = 0;
    while (i < N)
    {
      if (h[i] == 0)
        i++; //0なら何もせずに進む
      else
      {
        res++; //区間の始まり
        while (i < N && h[i] > 0)
        {
          h[i]--; //ついでに引いとく
          i++;    //区間の終わりまで一気に
        }
      }
    }
  }
  cout << res << endl;
}
