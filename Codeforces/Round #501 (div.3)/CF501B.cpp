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
  string s, t;
  cin >> s >> t;
  if (s == t)
  {
    cout << 0 << endl;
    return;
  }

  map<char, int> scnt, tcnt;
  for (int i = 0; i < n; i++)
  {
    scnt[s[i]]++, tcnt[t[i]]++;
  }

  if (scnt != tcnt)
  {
    cout << -1 << endl;
    return;
  }

  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    if (s[i] != t[i])
    {
      for (int j = i + 1; j < n; j++)
      {
        if (s[j] == t[i])
        {
          for (int k = j - 1; k >= i; k--)
          {
            swap(s[k], s[k + 1]);
            ans.push_back(k);
          }
          break;
        }
      }
    }
  }
  cout << ans.size() << endl;
  for (auto &it : ans)
  {
    cout << it + 1 << " ";
  }
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
