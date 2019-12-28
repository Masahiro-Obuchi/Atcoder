#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;

int main()
{
  int t;
  cin >> t;
  vector<int> ans(t);
  for (int i = 0; i < t; i++)
  {
    int h = 0, m = 0;
    cin >> h >> m;
    if (m == 0)
    {
      ans[i] = (24 - h) * 60;
    }
    else
    {
      ans[i] = (24 - h - 1) * 60 + (60 - m);
    }
  }
  for (int i = 0; i < t; i++)
  {
    cout << ans[i] << endl;
  }
}
