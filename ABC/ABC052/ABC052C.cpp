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
  ll ans = 1;
  vector<ll> cnt(N + 1, 0LL);
  for (int i = 1; i <= N; i++)
  {
    vector<pair<ll, int>> tmp = factorize(i);
    for (auto a : tmp)
    {
      cnt[a.first] += a.second;
    }
  }
  for (int i = 2; i <= N; i++)
  {
    cerr << cnt[i] << endl;
    ans *= (cnt[i] + 1);
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
