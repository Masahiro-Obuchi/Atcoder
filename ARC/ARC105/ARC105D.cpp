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
  int N;
  cin >> N;
  vector<ll> a(N);
  for (auto &it : a)
    cin >> it;

  if (N == 1)
  {
    cout << "Second" << endl;
    return;
  }

  if (N % 2 != 0)
  {
    cout << "Second" << endl;
  }
  else
  {
    map<ll, ll> mp;
    for (auto it : a)
      mp[it]++;

    bool even = true;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
      if (itr->second % 2 != 0)
        even = false;
    }

    if (even)
    {
      cout << "Second" << endl;
    }
    else
    {
      cout << "First" << endl;
    }
  }
  return;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    solve();
  }
  return 0;
}
