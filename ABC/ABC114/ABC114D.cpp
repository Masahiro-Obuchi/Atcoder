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

// 素因数分解
vector<pair<long long, int>> factorize(long long N)
{
  vector<pair<long long, int>> res;
  for (long long i = 2; i * i <= N; i++)
  {
    if (N % i != 0)
      continue;
    res.emplace_back(i, 0);
    while (N % i == 0)
    {
      N /= i;
      res.back().second++;
    }
  }
  if (N != 1)
    res.emplace_back(N, 1);
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N;
  cin >> N;
  vector<int> cnt(101);
  for (int i = 2; i <= N; i++)
  {
    vector<pair<ll, int>> factor = factorize(i);
    for (auto &it : factor)
    {
      if (it.first >= 2)
      {
        cnt[it.first] += it.second;
      }
    }
  }
  int n3 = 0, n5 = 0, n15 = 0, n25 = 0, n75 = 0;
  for (int i = 2; i <= 100; i++)
  {
    if (cnt[i] >= 74)
      n75++;
    if (cnt[i] >= 24)
      n25++;
    if (cnt[i] >= 14)
      n15++;
    if (cnt[i] >= 4)
      n5++;
    if (cnt[i] >= 2)
      n3++;
  }
  if (n5 < 2)
    cout << 0 << endl;
  else
  {
    int ans = 0;
    ans += n5 * (n5 - 1) / 2 * (n3 - 2); // n5を2つ使うため，n3は2つ少なくなる
    ans += n15 * (n5 - 1);
    ans += n25 * (n3 - 1);
    ans += n75;
    cout << ans << endl;
  }
  return 0;
}

// 1から100まで約数を数えていく．まず約数の数が奇数であるから2乗出来る数　
// まず実際に32400を素因数分解してみると2^43^45^2となる．3つの異なる素数p, q, rを使ってp^4q^4r^2と表せる数は全て七五数となる．他にp^14q^5, p^24q^3, p^74というパターンの数も約数を75個持つ．75 = 3 * 5 * 5であるから以上の4パターンが全てでこれらをそれぞれ数え上げればよい．
