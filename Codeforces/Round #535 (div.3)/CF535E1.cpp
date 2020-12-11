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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &it : a)
    cin >> it;

  vector<int> l(m), r(m);
  for (int i = 0; i < m; i++)
  {
    cin >> l[i] >> r[i];
    l[i]--, r[i]--;
  }

  int ans = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());
  vector<int> res;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        continue;
      vector<int> b = a;
      vector<int> idxs;
      vector<int> imos(n + 1);
      for (int k = 0; k < m; k++)
      {
        if (l[k] <= i && i <= r[k])
        {
          imos[l[k]]--, imos[r[k] + 1]++;
          idxs.push_back(k);
        }
      }
      for (int k = 0; k < n; k++)
        imos[k + 1] += imos[k];
      for (int k = 0; k < n; k++)
        b[k] += imos[k];
      int tmp = b[j] - b[i];
      if (tmp > ans)
      {
        ans = tmp;
        res = idxs;
      }
    }
  }
  cout << ans << endl;
  cout << res.size() << endl;
  for (auto &it : res)
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
