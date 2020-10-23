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
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &it : a)
    cin >> it;

  sort(a.begin(), a.end());
  int l = 0, r = n + 1;
  while (r - l > 1)
  {
    int mid = (l + r) / 2;
    bool f = true;
    if (2 * mid + 1 > n)
    {
      f = false;
    }
    else
    {
      vector<int> b;
      int pos_a = 0, pos_b = n - (mid + 1);
      for (int i = 0; i < 2 * mid + 1; i++)
      {
        if (i % 2 == 0)
        {
          b.emplace_back(a[pos_b]);
          pos_b++;
        }
        else
        {
          b.emplace_back(a[pos_a]);
          pos_a++;
        }
      }
      for (int i = 1; i < 2 * mid + 1; i += 2)
      {
        if (b[i] >= b[i - 1] || b[i] >= b[i + 1])
        {
          f = false;
        }
      }
    }
    if (f)
      l = mid;
    else
      r = mid;
  }
  cout << l << endl;
  vector<int> b;
  int pos_a = 0, pos_b = n - (l + 1);
  for (int i = 0; i < 2 * l + 1; i++)
  {
    if (i % 2 == 0)
    {
      b.emplace_back(a[pos_b]);
      pos_b++;
    }
    else
    {
      b.emplace_back(a[pos_a]);
      pos_a++;
    }
  }
  for (int i = pos_a; i < n - (l + 1); i++)
  {
    b.emplace_back(a[i]);
  }
  for (auto &c : b)
  {
    cout << c << " ";
  }
  return;
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
