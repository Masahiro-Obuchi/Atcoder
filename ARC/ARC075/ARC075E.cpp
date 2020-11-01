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

template <typename T>
struct BIT
{
  int n;         // 配列の要素数(数列の要素数+1)
  vector<T> bit; // データの格納先
  BIT(int n_) : n(n_ + 1), bit(n, 0) {}
  void add(int i, T x)
  {
    for (int idx = i; idx < n; idx += (idx & -idx))
    {
      bit[idx] += x;
    }
  }
  T sum(int i)
  {
    T s(0);
    for (int idx = i; idx > 0; idx -= (idx & -idx))
    {
      s += bit[idx];
    }
    return s;
  }

  // [l,r) の区間和を取得
  T query(int l, int r) { return sum(r - 1) - sum(l - 1); }

  int lower_bound(T w)
  { // a_1 + a_2 + ... + a_x >= w となるような最小の x を求める(ただし a_i >= 0)
    if (w <= 0)
    {
      return 0;
    }
    else
    {
      int x = 0, r = 1;
      while (r < n)
        r = r << 1;
      for (int len = r; len > 0; len = len >> 1)
      { // 長さlenは1段下るごとに半分に
        if (x + len < n && bit[x + len] < w)
        { // 採用するとき
          w -= bit[x + len];
          x += len;
        }
      }
      return x + 1;
    }
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N, K;
  cin >> N >> K;
  vector<ll> a(N);
  for (auto &it : a)
    cin >> it;

  vector<ll> S(N + 1);
  for (int i = 0; i < N; i++)
  {
    S[i + 1] = S[i] + a[i] - K;
  }
  vector<ll> SS = S;
  sort(SS.begin(), SS.end());
  ll res = 0;
  BIT<ll> bit(N + 10);
  for (int i = 0; i <= N; i++)
  {
    int id = lower_bound(SS.begin(), SS.end(), S[i]) - SS.begin();
    res += bit.sum(id + 1);
    // cerr << bit.sum(id + 1) << endl;
    bit.add(id + 1, 1);
  }
  cout << res << endl;
  return 0;
}

// a,b,c,…  の平均値が K 以上
// ⇔ a−K, b−K, c−K,… の平均値が 0 以上
// ⇔ a−K, b−K, c−K,… の総和が 0 以上 これらの累積和をSiとしてN+1個の整数S0, S1, ..., SNに対してSj - Si>=0が成立するような0<=i<j<Nの組が何個あるかを求めよ
