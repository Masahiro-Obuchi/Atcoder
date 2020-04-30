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
  int N, K;
  cin >> N >> K;
  vector<double> R(N);
  for (int i = 0; i < N; i++)
    cin >> R[i];
  sort(R.begin(), R.end(), greater<double>());
  double ans = 0.0;
  vector<double> RK;
  for (int i = 0; i < K; i++)
    RK.push_back(R[i]);
  sort(RK.begin(), RK.end());
  for (int i = 0; i < K; i++)
  {
    ans += RK[i];
    ans /= 2.0;
  }
  cout << setprecision(10) << fixed << ans << endl;
  return 0;
}
