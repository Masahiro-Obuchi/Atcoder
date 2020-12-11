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
  int q;
  cin >> q;
  vector<pair<P, P>> rec(200010);
  int cnt = 0, Lcnt = 0, Rcnt = 0;
  for (int i = 0; i < q; i++)
  {
    char t;
    int id;
    cin >> t >> id;
    if (t == '?')
    {
      cout << min(Lcnt - rec[id].second.first + rec[id].first.first, Rcnt - rec[id].second.second + rec[id].first.second) << endl;
    } // 左に何回足されたか + 元々左に何冊あったか 右も同様
    else if (t == 'L')
    {
      Lcnt++;
      rec[id].first.first = 0, rec[id].first.second = cnt;
      rec[id].second.first = Lcnt, rec[id].second.second = Rcnt;
      cnt++;
    }
    else
    {
      Rcnt++;
      rec[id].first.first = cnt, rec[id].first.second = 0;
      rec[id].second.first = Lcnt, rec[id].second.second = Rcnt;
      cnt++;
    }
  }
}
// vectorに本が置かれた際に左右に何冊あるかと，今までに何回LとRが置かれたかを記録しておく　これをすることでクエリが来た際に元々左右に何冊置かれていたかと，その後に左と右に何冊置かれたかを求めることが出来る　これを足して左右で最小を取ったものが答えとなる

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
