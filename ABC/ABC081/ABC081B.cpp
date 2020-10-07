#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> avec(N);
  for (auto &a : avec)
  {
    cin >> a;
  }
  int ans = 0;
  bool exist = false;
  while (!exist)
  {
    bool exist2 = false;
    for (int i = 0; i < N; i++)
    {
      if (avec[i] % 2 != 0)
      {
        exist2 = true;
        break;
      }
    }
    if (exist2)
    {
      exist = true;
      break;
    }
    for (int i = 0; i < N; i++)
    {
      avec[i] /= 2;
    }
    ans++;
  }
  cout << ans << endl;
}
