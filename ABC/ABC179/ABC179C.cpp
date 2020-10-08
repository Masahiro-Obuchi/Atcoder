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
  ll N;
  cin >> N;
  ll ans = 0;
  for (ll A = 1; A <= N; A++)
  {
    ans += (N - 1) / A;
  }
  cout << ans << endl;
  return 0;
}
// A*B + C = N N = A*B + C N - C = A * B Cは1以上よりN-1以下となるA*Bの組み合わせを求める
// A*B <= N - 1なら求めるCがある　Aを全探索して固定したと考えたときにB <= (N-1)/A(切り捨て)であるから(N-1)/Aを足し合わせていけばよい
