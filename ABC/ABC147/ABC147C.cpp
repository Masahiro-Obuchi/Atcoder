#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<vector<int>> a(N, vector<int>(N, -1));
  for (int i = 0; i < N; i++)
  {
    int A;
    cin >> A;
    for (int j = 0; j < A; j++)
    {
      int x, y;
      cin >> x >> y;
      x--;
      a[i][x] = y;
    }
  }
  int ans = 0;
  for (int bit = 0; bit < (1 << N); bit++)
  {
    vector<int> b(N, -1);
    int cnt = 0;
    bool ng = false;
    for (int i = 0; i < N; i++)
    {
      if (bit & (1 << i))
      {
        if (b[i] == -1)
          b[i] = 1;
        else if (b[i] != 1) {
          ng = true;
          break;
        }
        for (int j = 0; j < N; j++)
        {
          if (a[i][j] != -1)
          {
            if (b[j] == -1)
            {
              b[j] = a[i][j];
            }
            else
            {
              if (b[j] != a[i][j])
              {
                ng = true;
                break;
              }
            }
          }
        }
        if (ng)
          break;
      } else {
        if (b[i] == -1) b[i] = 0;
        else {
          if (b[i] != 0) ng = true;
        }
      }
    }
    if (!ng)
    {
      for (int i = 0; i < 15; i++)
      {
        if (b[i] == 1) {
          cnt++;
        }
      }
      ans = max(ans, cnt);
    }
  }
  cout << ans << endl;
}

// bit全探索を用いて正直者を決め打ち　各bitで出来るか出来ないかをboolとして保持しておく．
// iのbitが立っているときにもしb[i] == -1ならb[i] = 1とし，そうでなければb[i] == 1ならばok, そうでなければその回のboolをfalseとして，breakする．
// iのbitが立っていなければもしb[i] == -1ならb[i] = 0とし，そうでなければ，b[i] == 0ならばok, そうでなければその回のboolをfalseとする．
