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
  map<int, int> cnt;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    cnt[x]++;
  }

  vector<int> cnts;
  for (auto itr = cnt.begin(); itr != cnt.end(); itr++)
  {
    cnts.push_back(itr->second);
  }

  sort(cnts.begin(), cnts.end());

  int ans = 0;
  for (int i = 1; i <= cnts.back(); i++)
  {
    int pos = (int)cnts.size() - 1;
    int cur = i;
    int res = cur;
    while (cur % 2 == 0 && pos > 0) // O(logn)になる
    {
      cur /= 2;
      --pos;
      if (cnts[pos] < cur) // cnts[pos]にcur個の問題が存在しなかった場合，break
        break;
      res += cur;
    }
    ans = max(ans, res);
  }
  cout << ans << endl;
  return;
}
// 貪欲に取っていく
// nlognという計算量が見積れるかが本質

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
