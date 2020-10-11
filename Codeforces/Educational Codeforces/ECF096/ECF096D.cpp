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
  if (s.size() == 1)
  {
    cout << 1 << endl;
    return;
  }

  vector<pair<char, int>> cnts;
  int now = s[0];
  int ct = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == now)
    {
      ct++;
    }
    else
    {
      cnts.push_back({s[i - 1], ct});
      now = s[i];
      ct = 1;
    }
  }
  if (ct >= 1)
  {
    cnts.push_back({s[n - 1], ct});
  }

  int right = 0;
  int ans = 0;
  int m = cnts.size();
  int greater_two_idx = m;
  for (int i = 0; i < cnts.size(); i++)
  {
    if (cnts[i].second >= 2)
    {
      greater_two_idx = i;
      break;
    }
  }

  while (right < m)
  {
    if (right == greater_two_idx)
    {
      greater_two_idx++;
      while (greater_two_idx < m)
      {
        if (cnts[greater_two_idx].second >= 2)
          break;
        greater_two_idx++;
      }
    }
    if (cnts[right].second > 1)
    {
      ans++;
      right++;
    }
    else
    {
      //cerr << "m: " << m << "  greater_two_idx: " << greater_two_idx << endl;
      if (greater_two_idx != m)
      {
        ans++;
        cnts[greater_two_idx].second--;
        right++;
        if (cnts[greater_two_idx].second == 1)
        {
          while (greater_two_idx < m)
          {
            if (cnts[greater_two_idx].second >= 2)
              break;
            greater_two_idx++;
          }
        }
      }
      else
      {
        ans++;
        right += 2;
      }
    }
  }
  cout << ans << endl;
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
