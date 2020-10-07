#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> req(M);
  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    req[i].first = b;
    req[i].second = a;
  }
  sort(req.begin(), req.end());

  int ans = 1;
  int t = req[0].first; // tは最後に選んだ区間の終点
  for (int i = 1; i < M; i++)
  {
    if (t <= req[i].second)
    {
      ans++;
      t = req[i].first;
    }
  }
  cout << ans << endl;
}
