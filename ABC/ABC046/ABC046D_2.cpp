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
//using Graph = vector<vector<Edge>>;
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;
const double PI = acos(-1.0);

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int P = 0;
  int G = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == 'p')
      P++;
    else
      G++;
  }
  int ans = (G - P) / 2; // Gが1個減ってPが1個増えるから
  cout << ans << endl;
  return 0;
}
// (別解)とりあえずTopCoDeer君は条件を満たした手の出し方をしているからTopCoDeer君と同じ手を出し続ければ必ず0点になる．その上でパーを出した回数とグーを出した回数を数えて条件を満たす数を数えて後ろからパーに変えていけばよい．
