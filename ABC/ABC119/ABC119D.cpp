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
  int A, B, Q;
  cin >> A >> B >> Q;
  vector<ll> s(A), t(B);
  for (int i = 0; i < A; i++)
  {
    cin >> s[i];
  }
  for (int i = 0; i < B; i++)
  {
    cin >> t[i];
  }
  s.push_back(INF), s.push_back(-INF);
  t.push_back(INF), t.push_back(-INF);
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  for (int i = 0; i < Q; i++)
  {
    ll x;
    cin >> x;
    int sa, sb, ta, tb;
    sb = upper_bound(s.begin(), s.end(), x) - s.begin();
    sa = sb;
    sa--;
    tb = upper_bound(t.begin(), t.end(), x) - t.begin();
    ta = tb;
    ta--;
    ll res = INF;
    // 最初にsを訪れる
    for (int i = 0; i < 2; i++)
    {
      ll first = (i ? s[sa] : s[sb]);
      for (int j = 0; j < 2; j++)
      {
        ll second = (j ? t[ta] : t[tb]);
        res = min(res, abs(x - first) + abs(second - first));
      }
    }
    // 最初にtを訪れる
    for (int i = 0; i < 2; i++)
    {
      ll first = (i ? t[ta] : t[tb]);
      for (int j = 0; j < 2; j++)
      {
        ll second = (j ? s[sa] : s[sb]);
        res = min(res, abs(x - first) + abs(second - first));
      }
    }
    cout << res << endl;
  }
  return 0;
}

// 二分探索で最も近い西の寺と東の寺，西の神社と東の神社をそれぞれsa, sb, ta, tbとする．これらをどの順番で訪れるかで8通りを全探索する．sa->ta, sa->tb, sb->ta, sb->tbとその逆順．配列外アクセスにならないようにINF, -INFの位置に番兵があるとする．
