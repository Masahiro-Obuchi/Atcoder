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

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
  ll g = gcd(a, b);
  return a / g * b;
}

ll dfs(int v, vector<ll> &p, vector<ll> &q, vector<ll> &l, vector<ll> &r)
{
  ll left = l[v], right = r[v];

  ll lv = (left == -1) ? 1 : dfs(left, p, q, l, r);
  ll rv = (right == -1) ? 1 : dfs(right, p, q, l, r);

  ll L = lcm(p[v] * lv, q[v] * rv);
  return L / p[v] + L / q[v];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<ll> p(n), q(n), l(n), r(n);
  vector<ll> root(n);

  iota(root.begin(), root.end(), 0);

  for (int i = 0; i < n; i++)
  {
    cin >> p[i] >> q[i] >> l[i] >> r[i];
    l[i]--, r[i]--;

    // rootを求めるための処理　それ以外の頂点は消していく
    if (l[i] != -1)
      root.erase(find(root.begin(), root.end(), l[i]));
    if (r[i] != -1)
      root.erase(find(root.begin(), root.end(), r[i]));
  }

  ll ans = dfs(root[0], p, q, l, r);
  cout << ans << endl;
  return 0;
}

// 両方ともおもりをつけるところ，かつ一番深いところから決めていく．　おもりの決め方は重い方はgcd(赤までの距離，青までの距離)，軽い方は　min(赤までの距離，青までの距離)/gcd(赤までの距離，青までの距離)　・片方が決まっている場合　もう一個のおもりの重さ*(相手側の長さ)/(自分側の長さ)
// 完全二分木のような構造になっているから木DPのようにして求めることが出来る　各棒においてf(i) = i番目の棒で求まるこの下にあるおもりの重さの合計の最小とする．
// 支点から左端までの長さpと支点から右端までの長さqを既約にしておくと、つりあわせるための最小の重さはLCM(p*左のモビールの重さ, q*右のモビールの重さ)になりそうな感じ。再帰的にやるとうまくいきそうなのでそうする。
// 最小公倍数はa, bをできるだけ小さい状態でat = sbとして一致させたい，というもの
// 受け取ったおもりwl, wrに関してwl*l = wr*rは成り立たない．よって(Wl * s) * l = (wr * t) * rとなる最小のs,tを求めればこの棒で求まる重みwl' = wl*s, wr' = wr*tとなる．ここで[$ w_l * l]と[$ w_r * r]を等しくしたい、ただし出来るだけ小さい値にとどめたい、というのが上の式である。 すると、これは[最小公倍数] となる。
// [最小公倍数]は、[$ a, b]を出来るだけ小さい状態で[$ at = sb]として一致させたい、というものである。
