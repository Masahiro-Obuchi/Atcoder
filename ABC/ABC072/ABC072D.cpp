#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> p(N);
  for (int i = 0; i < N; i++)
  {
    cin >> p[i];
    p[i]--;
  }
  int ans = 0;
  if (p[0] == 0)
  {
    swap(p[0], p[1]);
    ans++;
  }
  if (p[N - 1] == N - 1)
  {
    swap(p[N - 1], p[N - 2]);
    ans++;
  }
  for (int i = 1; i < N - 1; i++)
  {
    if (p[i] == i)
    {
      if (p[i - 1] == i - 1)
      {
        swap(p[i], p[i - 1]);
        ans++;
        continue;
      }
      else if (p[i + 1] == i + 1)
      {
        swap(p[i], p[i + 1]);
        ans++;
        continue;
      }
      else
      {
        swap(p[i], p[i - 1]);
        ans++;
        continue;
      }
    }
  }
  cout << ans << endl;
}

// 順番に前からiとi+1をswapしていくのが得となる．（iとi-1をswapしてしまうとi-1は既にoになっているので損をしてしまう．ex. 1, 2, 3, 4, 5, 6
// 1と2, 3と1, 4と1, ...などと多めにswapすることになってしまう
// N - 1のときはN - 2とN - 1をswapするしかない
