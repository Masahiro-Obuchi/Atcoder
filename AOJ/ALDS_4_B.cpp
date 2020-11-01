#include <bits/stdc++.h>
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
  vector<ll> S(n);
  for (int i = 0; i < n; i++)
    cin >> S[i];
  int q;
  cin >> q;
  vector<ll> T(q);
  for (int i = 0; i < q; i++)
    cin >> T[i];
  int cnt = 0;
  for (int i = 0; i < q; i++)
  {
    if (binary_search(S.begin(), S.end(), T[i]))
      cnt++;
  }
  cout << cnt << endl;
  return 0;
}
