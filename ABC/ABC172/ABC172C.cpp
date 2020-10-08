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
  ll N, M, K;
  cin >> N >> M >> K;
  vector<ll> A(N), B(M);
  for (auto &it : A)
    cin >> it;
  for (auto &it : B)
    cin >> it;
  vector<ll> ASum(N + 1);
  vector<ll> BSum(M + 1);
  for (int i = 0; i < N; i++)
  {
    ASum[i + 1] = ASum[i] + A[i];
  }
  for (int i = 0; i < M; i++)
  {
    BSum[i + 1] = BSum[i] + B[i];
  }
  ll ans = 0;
  for (int i = 0; i <= N; i++)
  {
    ll rem = K - ASum[i];
    if (rem < 0)
      continue;
    int idx = upper_bound(BSum.begin(), BSum.end(), rem) - BSum.begin();
    idx--;
    if (idx >= 0)
      ans = max(ans, (ll)i + idx);
    else
      ans = max(ans, (ll)i);
  }
  cout << ans << endl;
  return 0;
}

// 机Aからi冊，机Bからj冊読むことを考えれば問題は次のように言い換えられる．整数i,jをai + bj <= Kとなるように選ぶときi+jが取りうる最大の値を求めよ．(ai, bjは先頭からA[i], B[j]を足していった和)これはあらかじめAとBの累積和を計算しておく．そしてAから取る数を0～Nで回して残りの数をK - ASum[i](rem)で求める．この値が0より小さかったらアウト．配列BSumの中でremを超えないギリギリのインデックスを二分探索によって求めて(jとする)ansをi+jとansのmaxで更新していく．
