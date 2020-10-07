#include <bits/stdc++.h>
using namespace std;

int main()
{
  int X, Y, Z;
  cin >> X >> Y >> Z;
  X -= Z;
  int width = Y + Z;
  cout << X / width << endl;
  return 0;
}
