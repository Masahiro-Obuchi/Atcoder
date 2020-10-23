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
    ll weight;
    Edge(int t, ll w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
*/
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> c(n);
  for (auto &it : c)
    cin >> it;

  int right = 0;
  vector<int> cnt(n);
  cnt[right] = 1;
  int left_color = c[0];
  int prev_color = c[0];

  for (int i = 1; i < n; i++)
  {
    if (prev_color == c[i])
    {
      cnt[right]++;
    }
    else
    {
      if (i % 2 != 0)
      {
        if (right == 0)
        {
          cnt[right]++;
          left_color = 1 - left_color;
        }
        else
        {
          cnt[right - 1] += cnt[right] + 1;
          cnt[right] = 0;
          right--;
        }
      }
      else
      {
        right++;
        cnt[right] = 1;
      }
    }
    prev_color = c[i];
  }

  bool white = true;
  if (left_color)
    white = false;

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (white)
    {
      if (i % 2 == 0)
        ans += cnt[i];
    }
    else
    {
      if (i % 2 != 0)
        ans += cnt[i];
    }
  }
  cout << ans << endl;
  return 0;
}

// 左端の色と直前の色を記録する　また右端のidxを保持する　色が変わった際にidxはインクリメントされる　偶数の時に碁石を裏返す際は右端の1個前に右端のcntを足して右端のidxをデクリメントする．idxが0のときだけは例外でleft_colorの変更のみになる．
