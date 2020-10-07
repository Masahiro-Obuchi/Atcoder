#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  ll X, Y;
  cin >> X >> Y;
  vector<ll> a(N);
  for (int i = 0; i < N; i++)
    cin >> a[i];
  vector<ll> b(M);
  for (int i = 0; i < M; i++)
    cin >> b[i];
  int ans = 0;
  bool can = true;
  int idx_a = 0;
  int idx_b = 0;
  while (can)
  {
    ll now = a[idx_a] + X;
    idx_b = lower_bound(b.begin(), b.end(), now) - b.begin();
    if (idx_b == M)
      can = false;
    else
    {
      now = b[idx_b] + Y;
      idx_a = lower_bound(a.begin(), a.end(), now) - a.begin();
      ans++;
      if (idx_a == N)
        can = false;
    }
  }
  cout << ans << endl;
  return 0;
}
