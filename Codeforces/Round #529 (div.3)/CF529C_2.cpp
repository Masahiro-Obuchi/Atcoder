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
  map<int, int> ans;
  queue<int> que;
  for (int i = 0; i <= 30; i++)
  {
    if (n & (1 << i))
    {
      if (i > 0)
        que.push(1 << i); // 2で割れるもののみ追加する
      ans[1 << i]++;
    }
  }

  if (ans.size() > k)
  {
    cout << "NO" << endl;
    return;
  }

  int cnt = ans.size();
  while (cnt < k && !que.empty())
  {
    int z = que.front();
    que.pop();
    ans[z]--;
    ans[z / 2] += 2;
    if (z / 2 > 1)
    {
      que.push(z / 2);
      que.push(z / 2);
    }
    cnt++;
  }
  if (cnt < k)
  {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  for (auto &it : ans)
  {
    for (int i = 0; i < it.second; i++)
    {
      cout << it.first << " ";
    }
  }
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
