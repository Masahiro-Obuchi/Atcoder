#include <bits/stdc++.h>
using namespace std;

int main()
{
  int h;
  cin >> h;
  int w;
  cin >> w;
  vector<string> a(h);
  for (int i = 0; i < h; i++)
  {
    cin >> a[i];
  }

  vector<bool> row(h, false); // このboolのvectorが大事
  vector<bool> col(w, false);
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if (a[i][j] == '#')
      {
        row[i] = true; // 黒がある行と列をマークする
        col[j] = true;
      }
    }
  }
  for (int i = 0; i < h; i++)
  {
    if (row[i]) // マークされている行であれば
    {
      for (int j = 0; j < w; j++)
      {
        if (col[j]) // 列全てを見たうえでマークされている列であれば
        {
          cout << a[i][j];
        }
      }
      cout << endl;
    }
  }
}

// まず，黒いマスが含まれる行および列をマーク．その後，マークされ行とマークされた列が交差する位置のaijのみを出力すればよい
// この問題はもう一度復習して自力で解きなおすべき
