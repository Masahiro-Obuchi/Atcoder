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
  ll N, D, K;
  cin >> N >> D >> K;
  vector<ll> L(D), R(D);
  for (int i = 0; i < D; i++)
    cin >> L[i] >> R[i];
  vector<ll> S(K), T(K);
  for (int i = 0; i < K; i++)
    cin >> S[i] >> T[i];
  vector<int> ans(K);
  for (int i = 0; i < K; i++)
  {
    bool right;
    if (S[i] < T[i])
      right = true;
    else
      right = false;
    int now = S[i];
    for (int j = 0; j < D; j++)
    {
      if (right)
      {
        if ((L[j] <= now && now <= R[j]) && (L[j] <= T[i] && T[i] <= R[j]))
        {
          ans[i] = j + 1;
          break;
        }
        if (L[j] <= now && now <= R[j])
          now = R[j];
      }
      else
      {
        if ((L[j] <= now && now <= R[j]) && (L[j] <= T[i] && T[i] <= R[j]))
        {
          ans[i] = j + 1;
          break;
        }
        if (L[j] <= now && now <= R[j])
          now = L[j];
      }
    }
  }
  for (auto a : ans)
    cout << a << endl;
  return 0;
}
