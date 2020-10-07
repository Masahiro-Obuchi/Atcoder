#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N);
  for (auto &it : A)
    cin >> it;
  map<ll, ll> mp;
  ll ans = 0;
  ll total = 0;
  for (int i = 0; i < N; i++)
  {
    mp[total]++;
    total += A[i];
    total %= M;
    ans += mp[total];
  }
  cout << ans << endl;
  return 0;
}
