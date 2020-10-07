#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;
  vector<string> svec(H);
  for (int i = 0; i < H; i++)
  {
    cin >> svec[i];
  }
  for (int i = 0; i < H; i++)
  {
    cout << svec[i] << endl;
    cout << svec[i] << endl;
  }
}

// この問題では，出力する画像をピクセルごとに求める方針でも解くことが出来るが，出力する画像の1, 2行目は元の画像の1行目，3, 4行目は元の画像の2行目...のように，上の行から順に2回出力を繰り返せばよい
