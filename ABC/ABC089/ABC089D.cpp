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
//using Graph = vector<vector<Edge>>;
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;
const double PI = acos(-1.0);

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W, D;
  cin >> H >> W >> D;
  // vector<vector<int>> A(H, vector<int>(W));
  vector<P> A(H * W);
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      int a;
      cin >> a;
      a--;
      A[a].first = i;
      A[a].second = j;
    }
  }
  vector<int> S(H * W + 1);
  for (int i = 0; i < D; i++)
  {
    int s = i;
    S[s] = 0;
    for (int j = 1; s + D * j < H * W; j++)
    {
      int now = s + D * j;
      S[now] = S[now - D] + abs(A[now].first - A[now - D].first) + abs(A[now].second - A[now - D].second);
    }
  }
  int Q;
  cin >> Q;
  vector<int> L(Q), R(Q);
  for (int i = 0; i < Q; i++)
  {
    cin >> L[i] >> R[i];
    L[i]--;
    R[i]--;
  }
  for (int i = 0; i < Q; i++)
  {
    ll ans = 0;
    if (L[i] == R[i])
      cout << ans << endl;
    else
    {
      ans = S[R[i]] - S[L[i]];
      cout << ans << endl;
    }
  }
  return 0;
}

// 累積和 Lは含まれないからLごと引く
