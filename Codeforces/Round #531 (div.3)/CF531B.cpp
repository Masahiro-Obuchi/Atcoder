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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &it : a)
    cin >> it;

  map<int, int> mp;
  for (int i = 0; i < n; i++)
  {
    mp[a[i]]++;
  }

  for (auto itr = mp.begin(); itr != mp.end(); itr++)
  {
    if (itr->second > k)
    {
      cout << "NO" << endl;
      return;
    }
  }

  vector<int> color(k + 1, 1);
  vector<vector<bool>> used(5010, vector<bool>(k + 1, false));

  vector<int> ans(n);
  int now = 0;
  for (int i = 0; i < n; i++)
  {
    while (used[a[i]][now])
    {
      now++;
      now %= k;
    }
    ans[i] = now;
    used[a[i]][now] = true;
    now++;
    now %= k;
  }
  cout << "YES" << endl;
  for (auto &it : ans)
    cout << it + 1 << " ";
  cout << endl;
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
