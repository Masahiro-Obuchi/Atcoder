#include <bits/stdc++.h>
using namespace std;

int main()
{
  int s;
  cin >> s;
  vector<int> a(1000001);
  a.at(0) = s;
  int i = 1;
  bool can = false;
  while (true)
  {
    if (a.at(i - 1) % 2 == 0)
      a.at(i) = a.at(i - 1) / 2;
    else
      a.at(i) = 3 * a.at(i - 1) + 1;
    int j = 0;
    while (j < i)
    {
      if (a.at(j) == a.at(i))
      {
        can = true;
        break;
      }
      else
        j++;
    }
    if (can)
      break;
    i++;
  }
  cout << i + 1 << endl;
}
