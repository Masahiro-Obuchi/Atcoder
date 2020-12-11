#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
/*
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
*/
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

void solve()
{
  int n, r;
  cin >> n >> r;
  vector<int> a(n);
  for (auto &it : a)
    cin >> it;

  int res1 = 0;
  vector<bool> is_warmed(n, false);
  for (int i = 0; i < n; i++)
  {
    if (!is_warmed[i])
    {
      bool used = false;
      int idx = -1;
      for (int j = i + r - 1; j >= i - r + 1; j--)
      {
        if (j < 0 || j >= n)
          continue;
        if (a[j] == 1)
        {
          res1++;
          used = true;
          idx = j;
          break;
        }
      }
      if (!used)
      {
        res1 = -1;
        break;
      }
      else
      {
        for (int j = idx + r - 1; j >= idx - r + 1; j--)
        {
          if (j < 0 || j >= n)
            continue;
          is_warmed[j] = true;
        }
      }
    }
  }

  cout << res1 << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  t = 1;
  for (int i = 0; i < t; i++)
  {
    solve();
  }
  return 0;
}

// to do: リファクタリング
// 予めそこを照らすことが出来る最も右のheaterを求めていればO(N)で解ける（imos法などで）
