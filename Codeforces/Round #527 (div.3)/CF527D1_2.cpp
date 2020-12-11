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
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i] %= 2;
  }

  set<P> seg, even;
  for (int i = 0; i < n; i++)
  {
    int j = i;
    while (j + 1 < n && a[j + 1] == a[j])
    {
      j++;
    }
    seg.insert({i, j});
    if ((j - i + 1) % 2 == 0)
      even.insert({i, j});
    i = j;
  }

  while (seg.size() > 1 && !even.empty())
  {
    auto cur = *even.begin();
    even.erase(cur);
    seg.erase(cur);
    auto it = seg.lower_bound(cur);
    if (it != seg.end())
    {
      cur.second = it->second;
      if ((it->second - it->first + 1) % 2 == 0)
        even.erase(*it);
      seg.erase(it);
    }
    it = seg.lower_bound(cur);
    if (it != seg.begin())
    {
      it--;
      cur.first = it->first;
      if ((it->second - it->first + 1) % 2 == 0)
        even.erase(*it);
      seg.erase(it);
    }
    seg.insert(cur);
    if ((cur.second - cur.first + 1) % 2 == 0)
      even.insert(cur);
  }

  if (seg.size() == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
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
