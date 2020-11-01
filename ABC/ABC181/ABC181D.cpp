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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string S;
  cin >> S;
  if (S.size() == 1)
  {
    if (S == "8")
    {
      cout << "Yes" << endl;
      return 0;
    }
    cout << "No" << endl;
  }
  else if (S.size() == 2)
  {
    if (stoi(S) % 8 == 0)
    {
      cout << "Yes" << endl;
      return 0;
    }
    swap(S[0], S[1]);
    if (stoi(S) % 8 == 0)
    {
      cout << "Yes" << endl;
      return 0;
    }
    cout << "No" << endl;
  }
  else
  {
    vector<int> cnt(10);
    for (int i = 0; i < S.size(); i++)
    {
      cnt[S[i] - '0']++;
    }
    for (int i = 112; i < 1000; i += 8)
    {
      auto c = cnt;
      for (char x : to_string(i))
        c[x - '0']--;
      bool ok = true;
      for (auto it : c)
      {
        if (it < 0)
          ok = false;
      }
      if (ok)
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
    cout << "No" << endl;
  }
  return 0;
}
