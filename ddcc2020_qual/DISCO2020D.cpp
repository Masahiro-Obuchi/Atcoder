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
    ll weight;
    Edge(int t, ll w) : to(t), weight(w) {}
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
  int M;
  cin >> M;
  vector<ll> d(M), c(M);
  for (int i = 0; i < M; i++)
    cin >> d[i] >> c[i];
  ll digits = 0;
  ll sum = 0;
  for (int i = 0; i < M; i++)
  {
    digits += c[i];
    sum += d[i] * c[i];
  }
  ll ans = digits - 1;
  ans += (sum - 1) / 9;
  cout << ans << endl;
  return 0;
}

// 桁和は1以上9以下にならないといけないからsumから1引いた値を9で割る　9で割るのは桁和を9減らす行為を繰り返すから　これが出来るのは(sum - 1)/9回
