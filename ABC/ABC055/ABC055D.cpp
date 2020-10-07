#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
// using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  string s;
  cin >> s;
  s += s[0];
  s += s[1];
  for (int c = 0; c < 4; c++)
  {
    string ans;
    if (c == 0)
    {
      ans += 'S';
      ans += 'S';
    }
    else if (c == 1)
    {
      ans += 'S';
      ans += 'W';
    }
    else if (c == 2)
    {
      ans += 'W';
      ans += 'S';
    }
    else
    {
      ans += 'W';
      ans += 'W';
    }
    for (int i = 2; i <= N + 1; i++)
    {
      if (ans[i - 1] == 'S')
      {
        if (s[i - 1] == 'o')
        {
          ans += ans[i - 2];
        }
        else
        {
          ans += (ans[i - 2] == 'S') ? 'W' : 'S';
        }
      }
      else
      {
        if (s[i - 1] == 'o')
        {
          ans += (ans[i - 2] == 'S') ? 'W' : 'S';
        }
        else
        {
          ans += ans[i - 2];
        }
      }
      if (i == N + 1)
      {
        if (ans[0] == ans[N] && ans[1] == ans[N + 1])
        {
          for (int i = 0; i < N; i++)
            cout << ans[i];
          cout << endl;
          return 0;
        }
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
