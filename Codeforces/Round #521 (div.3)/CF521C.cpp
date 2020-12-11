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
  ll sum = 0;
  for (auto &it : a)
  {
    cin >> it;
    sum += it;
  }

  vector<ll> b = a;
  sort(b.begin(), b.end());
  int nowMax = 0;
  int nowSecondMax = 0;
  for (int i = 0; i < n; i++)
  {
    if (b[i] >= nowMax)
    {
      nowSecondMax = nowMax;
      nowMax = b[i];
    }
  }

  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == nowMax)
    {
      if (sum - a[i] - nowSecondMax == nowSecondMax)
        ans.push_back(i);
    }
    else
    {
      if (sum - a[i] - nowMax == nowMax)
        ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for (auto &it : ans)
    cout << it + 1 << " ";
  cout << endl;
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
