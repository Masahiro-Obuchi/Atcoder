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
  int H, W;
  cin >> H >> W;

  map<int, int> s; // s[今]=開始の最大
  multiset<int> vals;

  for (int i = 0; i < W; i++)
    s[i] = i;
  for (int i = 0; i < W; i++)
    vals.insert(0);

  for (int i = 0; i < H; i++)
  {
    int l, r;
    cin >> l >> r;
    l--; // 半開区間
    auto it = s.lower_bound(l);
    int mr = -1;
    while (it != s.end() && it->first <= r)
    {
      mr = max(mr, it->second);
      int x = it->first - it->second;
      vals.erase(vals.find(x));
      s.erase(it++); // 消去してイテレータを進める
    }
    if (mr != -1 && r < W)
    {
      vals.insert(r - mr);
      s[r] = mr; // rを追加しておく
    }
    int ans = -1;
    if (vals.size() > 0)
    {
      ans = *vals.begin() + (i + 1);
    }
    cout << ans << endl;
  }
  return 0;
}
// (開始，今) multiset
// もう一度問題文と解説放送をよく見る．
