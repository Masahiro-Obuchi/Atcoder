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

struct rect
{
  int w;
  int d;
  rect(int w, int d) : w(w), d(d) {}
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, w, d;
  while (true)
  {
    cin >> n >> w >> d;
    if (n == 0 && w == 0 && d == 0)
      break;

    vector<int> p(n), s(n);
    for (int i = 0; i < n; i++)
    {
      cin >> p[i] >> s[i];
      p[i]--;
    }

    vector<rect> cake;
    cake.push_back({w, d});
    for (int i = 0; i < n; i++)
    {
      int width = cake[p[i]].w, depth = cake[p[i]].d;
      cake.erase(cake.begin() + p[i]);
      int d1, d2, w1, w2;

      while (s[i] > 2 * width + 2 * depth)
      {
        s[i] -= 2 * width + 2 * depth;
      }

      if (0 < s[i] && s[i] < width)
      {
        w1 = s[i], w2 = width - s[i];
        d1 = depth, d2 = depth;
      }
      else if (width < s[i] && s[i] < width + depth)
      {
        s[i] -= width;
        d1 = s[i], d2 = depth - s[i];
        w1 = width, w2 = width;
      }
      else if (width + depth < s[i] && s[i] < 2 * width + depth)
      {
        s[i] -= width + depth;
        w1 = s[i], w2 = width - s[i];
        d1 = depth, d2 = depth;
      }
      else
      {
        s[i] -= 2 * width + depth;
        d1 = s[i], d2 = depth - s[i];
        w1 = width, w2 = width;
      }
      if (d1 * w1 <= d2 * w2)
      {
        cake.push_back({w1, d1});
        cake.push_back({w2, d2});
      }
      else
      {
        cake.push_back({w2, d2});
        cake.push_back({w1, d1});
      }
    }
    vector<int> ans;
    for (int i = 0; i < cake.size(); i++)
    {
      ans.push_back(cake[i].w * cake[i].d);
    }
    sort(ans.begin(), ans.end());
    int sz = ans.size();
    for (int i = 0; i < sz; i++)
    {
      if (i == 0)
        cout << ans[i];
      else
        cout << " " << ans[i];
    }
    cout << endl;
  }
  return 0;
}
