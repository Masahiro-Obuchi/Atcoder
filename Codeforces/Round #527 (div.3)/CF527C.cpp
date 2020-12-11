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

string res;

bool check(const string &pref, const string &suf, vector<string> &v, int n)
{
  string s = pref + suf.substr(n - 2);
  multiset<string> vv, sPref, sSuf;
  for (int i = 0; i < n - 1; i++)
  {
    sPref.insert(s.substr(0, n - i - 1));
    vv.insert(s.substr(0, n - i - 1));
    sSuf.insert(s.substr(i + 1));
    vv.insert(s.substr(i + 1));
  }
  if (vv == multiset<string>(v.begin(), v.end())) // この記法覚える
  {
    for (int i = 0; i < 2 * n - 2; i++)
    {
      if (sPref.count(v[i]))
      { // キーの要素数を返す
        res += "P";
        sPref.erase(sPref.find(v[i]));
      }
      else if (sSuf.count(v[i]))
      {
        res += "S";
        sSuf.erase(sSuf.find(v[i]));
      }
      else
      {
        assert(false);
      }
    }
    return true;
  }
  return false;
}

void solve()
{
  int n;
  cin >> n;
  vector<string> s(2 * n - 2);
  vector<string> big;
  for (int i = 0; i < 2 * n - 2; i++)
  {
    cin >> s[i];
    if (s[i].size() == n - 1)
      big.push_back(s[i]);
  }

  if (check(big[0], big[1], s, n))
  {
    cout << res << endl;
  }
  else
  {
    check(big[1], big[0], s, n);
    cout << res << endl;
  }
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
