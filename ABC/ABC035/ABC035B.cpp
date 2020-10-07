#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  int T;
  cin >> T;
  int ans = 0;
  int temp_x = 0;
  int temp_y = 0;
  int num = 0;
  for (int i = 0; i < S.size(); i++)
  {
    if (S.at(i) == 'U')
    {
      temp_y++;
    }
    else if (S.at(i) == 'D')
      temp_y--;
    else if (S.at(i) == 'R')
      temp_x++;
    else if (S.at(i) == 'L')
      temp_x--;
    else
    {
      num++;
    }
  }
  if (T == 1)
  {
    if (temp_x >= 0)
    {
      temp_x += num;
    }
    else
    {
      temp_x -= num;
    }
    ans = abs(temp_x) + abs(temp_y);
  }
  else
  {
    for (int i = 1; i <= num; i++)
    {
      if (temp_x > 0)
        temp_x--;
      else if (temp_x < 0)
        temp_x++;
      else if (temp_x == 0 and temp_y > 0)
        temp_y--;
      else if (temp_x == 0 and temp_y < 0)
        temp_y++;
      else if (temp_x == 0 and temp_y == 0)
        temp_x++;
    }
    ans = abs(temp_x) + abs(temp_y);
  }
  if (T == 1)
    cout << ans << endl;
  else
    cout << ans << endl;
}

// 再帰関数？？　距離の最大値と最小値だけ分かればよいことに着目
// 最終的な最小値だけ分かればよいことに着目
// 最終的な位置が原点から遠くなる，あるいは原点に近くなる方向に移動することだけを考えればよい
// 移動した向きが分からない命令は動かないようにしたときのドローン最終的な位置を(x,y)とする．X>=0ならば？をRにし，x<0ならばLにすることで遠ざかることが出来る．
// ?を同じ向きにのみ移動するように置換するのが最適
// 最小値の場合は，UとLも考えるが(0, 0)となるコーナーケースが出現
// 原点にいる場合は遠ざかるしかできない

// int dist = abs(x) + abs(y);
//  if (dist > cnt) cout << dist - cnt << endl;
// else {
//  if ((cnt - dist) % 2 == 0)
//    cout << 0 << endl;
//    else
//      cout << 1 << endl;
//}
