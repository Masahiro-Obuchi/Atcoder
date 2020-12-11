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
  ll mx = 0;
  for (auto &it : a)
  {
    cin >> it;
    mx = max(mx, it);
  }
  vector<ll> st;

  for (int i = 0; i < n; i++)
  {
    if (a[i] == mx)
      continue;

    int j = i - 1;
    while (j + 1 < n && a[j + 1] != mx)
    {
      j++;
      if (!st.empty() && st.back() == a[j])
        st.pop_back();
      else if (st.empty() || st.back() > a[j])
      {
        st.push_back(a[j]);
      }
      else
      {
        cout << "NO" << endl;
        return;
      }
    }

    if (!st.empty())
    {
      cout << "NO" << endl;
      return;
    }
    i = j;
  }
  cout << "YES" << endl;
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
