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
  ll N, X, M;
  cin >> N >> X >> M;
  vector<int> occur(M, -1);
  ll A = X;
  occur[A] = 0;
  int start_loop = 0;
  int second = 0;
  int loop_size = 0;
  int cnt = 0;
  for (int i = 0; i < M; i++)
  {
    A = (A * A) % M;
    cnt++;
    if (occur[A] != -1)
    {
      loop_size = cnt - occur[A];
      second = cnt;
      start_loop = occur[A];
      break;
    }
    else
    {
      occur[A] = cnt;
    }
  }

  A = X;
  for (int i = 0; i < start_loop; i++)
  {
    A = (A * A) % M;
  }

  vector<ll> loop_sum(loop_size + 1);
  for (int i = start_loop; i < second; i++)
  {
    loop_sum[i - start_loop + 1] = loop_sum[i - start_loop] + A;
    A = (A * A) % M;
  }

  // cerr << loop_sum.size() << endl;

  if (second >= N)
  {
    A = X;
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
      ans += A;
      A = (A * A) % M;
    }
    cout << ans << endl;
  }
  else
  {
    A = X;
    ll ans = 0;
    for (int i = 0; i < start_loop; i++)
    {
      ans += A;
      A = (A * A) % M;
    }
    ans += (N - start_loop) / loop_size * loop_sum[loop_size];
    cerr << ans << endl;
    ll rem = (N - start_loop) % loop_size;
    ans += loop_sum[rem];
    cout << ans << endl;
  }
  return 0;
}
