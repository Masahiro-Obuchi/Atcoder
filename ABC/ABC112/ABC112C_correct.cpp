#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long> vx(N), vy(N), vh(N);
  int si = -1;
  for (int i = 0; i < N; i++)
  {
    cin >> vx[i] >> vy[i] >> vh[i];
    if (vh[i] > 0)
      si = i;
  } // h>0 の場所が一か所でも分かればよい

  long long resx = -1, resy = -1, resh = -1;
  for (long long x = 0; x <= 100; x++)
  {
    for (long long y = 0; y <= 100; y++)
    {
      long long h = vh[si] + abs(x - vx[si]) + abs(y - vy[si]); // H を計算する
      bool ok = true;
      for (int i = 0; i < N; i++)
      {
        if (vh[i] > 0 && h - vh[i] != abs(x - vx[i]) + abs(y - vy[i]))
          ok = false;
        if (vh[i] == 0 && h > abs(x - vx[i]) + abs(y - vy[i]))
          ok = false; //h=0のときはH-|x_i-C_X|-|y_i-C_Y|<0とならなければならない
      }
      if (ok)
        resx = x, resy = y, resh = h;
    }
  }
  cout << resx << " " << resy << " " << resh << endl;
}
