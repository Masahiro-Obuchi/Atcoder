#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> points(n);
  static bool isExist[5001][5001];

  for (int i = 0; i < n; i++)
  {
    cin >> points[i].first >> points[i].second;
    isExist[points[i].first][points[i].second] = true;
  }

  int ans = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int tmp = 0;
      int x1 = points[i].first, y1 = points[i].second;
      int x2 = points[j].first, y2 = points[j].second;
      tmp = (x1 - x2) * (x1 - x2) + (y1 - y2) * +(y1 - y2);
      if (tmp <= ans)
        continue;
      int x3 = x2 + y2 - y1;
      int y3 = y2 + x1 - x2;
      if (x3 < 0 || x3 > 5000 || y3 < 0 || y3 > 5000 || isExist[x3][y3] == false)
        continue;
      int x4 = x1 + y2 - y1;
      int y4 = y1 + x1 - x2;
      if (x4 < 0 || x4 > 5000 || y4 < 0 || y4 > 5000 || isExist[x4][y4] == false)
        continue;
      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
  return 0;
}

// 2点を決定すれば他の2点もすぐに求まり，O(N^2)で解くことが出来る．2点を決め打ちするというのがこの問題のポイント
// bool型の配列などで座標を指定したらそこに柱があるかどうかをすぐに分かるようにする．正方形の2つの頂点を決定すれば他の2つも定まるのですぐに求められる．
// 正方形の座標
