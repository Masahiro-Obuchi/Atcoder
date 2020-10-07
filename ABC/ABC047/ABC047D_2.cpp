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
  ll N, T;
  cin >> N >> T;
  vector<ll> A(N);
  for (auto &it : A)
    cin >> it;
  ll diff = 0;
  ll mi = A[0];
  for (int i = 0; i < N; i++)
  {
    ll now = A[i];
    if (now > mi)
      diff = max(now - mi, diff);
    mi = min(mi, now);
  }
  map<ll, int> mp;
  ll ans = 0;
  for (int i = 0; i < N; i++)
  {
    ll now = A[i];
    if (mp.find(A[i] - diff) != mp.end())
      ans++;
    mp[now]++;
  }
  cout << ans << endl;
  return 0;
}

// まずO(N)で利益の最大値を求める．そしてx = A[i] - A[j]すなわちA[i] - x == A[j]となるようなjの数を求める．
