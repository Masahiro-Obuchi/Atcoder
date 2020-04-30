#include <bits/stdc++.h>
using namespace std;

int main()
{
  bool girl = false;
  int txa, tya, txb, tyb, T, V;
  cin >> txa >> tya >> txb >> tyb >> T >> V;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    if (sqrt(pow((txa - x), 2) + pow((tya - y), 2)) + sqrt(pow((x - txb), 2) + pow((y - tyb), 2)) <= V * T)
      girl = true;
  }
  if (girl)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

// 問題文通りに実装するだけ問題
