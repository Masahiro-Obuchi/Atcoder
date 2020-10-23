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

bool check(ll x, vector<ll> &a, vector<ll> &b, ll N, ll K)
{
  ll cnt = 0;
  for (int i = 0; i < N; i++)
  {
    ll idx = upper_bound(b.begin(), b.end(), x / a[i]) - b.begin();
    cnt += idx;
  }

  if (cnt >= K)
    return true;
  else
    return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N, K;
  cin >> N >> K;
  vector<ll> a(N), b(N);
  for (auto &it : a)
    cin >> it;
  for (auto &it : b)
    cin >> it;

  sort(b.begin(), b.end());
  ll left = 0, right = INF;
  while (left + 1 < right)
  {
    ll mid = (left + right) / 2;
    if (check(mid, a, b, N, K))
      right = mid;
    else
      left = mid;
  }
  cout << right << endl;
  return 0;
}

// 小さい方からK番目がXであるとは？->  X-1以下の値はK個未満しかないが，X以下の数はK個以上あるということ　「X以下の数がK個以上であるような最小のX」が小さい方からK番目の数．単調性があるから二分探索が使える．
// ai*bj <= X <=> b_j <= X/Ai(切り捨て)　i行目に含まれるX以下の数の個数はb_1, b_2, ..., b_NのうちX/ai以下であるようなものの個数と一致．bをソートしておけばおけ．
