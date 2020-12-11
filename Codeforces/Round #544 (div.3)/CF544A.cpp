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
  string s1, s2;
  cin >> s1 >> s2;
  int h1 = 0, h2 = 0, m1 = 0, m2 = 0;
  h1 = (s1[0] - '0') * 10 + (s1[1] - '0');
  h2 = (s2[0] - '0') * 10 + (s2[1] - '0');
  m1 = (s1[3] - '0') * 10 + (s1[4] - '0');
  m2 = (s2[3] - '0') * 10 + (s2[4] - '0');
  cerr << h1 << " " << h2 << " " << m1 << " " << m2 << endl;
  int hans = 0, mans = 0;
  hans = h1 + (h2 - h1) / 2;
  if ((h2 - h1) % 2 == 0)
  {
    mans = m1 + (m2 - m1) / 2;
    if (mans >= 60)
    {
      hans++;
      mans -= 60;
    }
  }
  else
  {
    mans += 30;
    mans += m1 + (m2 - m1) / 2;
    if (mans >= 60)
    {
      hans++;
      mans -= 60;
    }
  }

  if (hans < 10)
    cout << "0" << hans << ":";
  else
    cout << hans << ":";
  if (mans < 10)
    cout << "0" << mans;
  else
    cout << mans;
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
