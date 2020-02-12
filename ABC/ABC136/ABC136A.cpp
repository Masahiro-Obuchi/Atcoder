#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B, C;
  cin >> A >> B >> C;
  if (C > A - B)
    cout << C - A + B << endl;
  else
    cout << 0 << endl;
  return 0;
}
