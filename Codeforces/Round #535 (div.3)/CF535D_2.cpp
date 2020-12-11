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
  string s;
  cin >> s;

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int j = i;
    while (j < n && s[i] == s[j])
    {
      j++;
    }
    string q = "RGB";
    q.erase(q.find(s[i]), 1);
    if (j < n)
    {
      q.erase(q.find(s[j]), 1);
    }
    for (int k = i + 1; k < j; k += 2)
    {
      ans++;
      s[k] = q[0];
    }
    i = j - 1;
  }
  cout << ans << endl;
  cout << s << endl;
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
