#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++)
    cin >> a[i];
  int minAns = 0, maxAns = 0;
  vector<int> ans(9, 0);
  for (int i = 0; i < N; i++)
  {
    if (a[i] >= 1 and a[i] <= 399)
      ans[0]++;
    else if (a[i] >= 400 and a[i] <= 799)
      ans[1]++;
    else if (a[i] >= 800 and a[i] <= 1199)
      ans[2]++;
    else if (a[i] >= 1200 and a[i] <= 1599)
      ans[3]++;
    else if (a[i] >= 1600 and a[i] <= 1999)
      ans[4]++;
    else if (a[i] >= 2000 and a[i] <= 2399)
      ans[5]++;
    else if (a[i] >= 2400 and a[i] <= 2799)
      ans[6]++;
    else if (a[i] >= 2800 and a[i] <= 3199)
      ans[7]++;
    else
      ans[8]++;
  }
  for (int i = 0; i < 8; i++)
  {
    if (ans[i] > 0)
      minAns++;
  }
  maxAns = minAns + ans[8];
  if (minAns == 0)
    minAns++;
  cout << minAns << " " << maxAns << endl;
}

// レート3199以下が存在しない場合を考慮する．色が一つもない場合は存在しないのでレート3199以下が誰もいない場合は全員が同じ色にする場合で最小値は1
