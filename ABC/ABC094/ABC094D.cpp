#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end(), greater<ll>());
  ll ans1, ans2;
  ans1 = *a.begin();
  ans2 = 0;
  ll d = 0;
  for (int i = 0; i < n; i++)
  {
    ll tmp = min(a[i], ans1 - a[i]);
    if (tmp > d)
    {
      ans2 = a[i];
      d = max(d, tmp);
    }
  }
  cout << ans1 << " " << ans2 << endl;
  return 0;
}

// 最大のものをnとしてn/2とA[i]との距離を計算し，距離が最も小さいものをrとする方が良さそう
