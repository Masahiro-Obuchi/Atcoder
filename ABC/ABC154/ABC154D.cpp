#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> p(N);
  vector<double> E(N);
  for (int i = 0; i < N; i++)
    cin >> p[i];
  double ans = 0.0;
  double now1, now2;
  for (int i = 0; i < K; i++)
  {
    now1 = 0.0;
    now2 = 0.0;
    for (int j = 1; j <= p[i]; j++)
    {
      now1 = j * (1.0 / p[i]);
      now2 += now1;
    }
    ans += now2;
    E[i] = now2;
  }
  double res = ans;
  double now3, now4;
  for (int i = 1; i < N - K + 1; i++)
  {
    ans -= E[i - 1];
    now3 = 0.0;
    now4 = 0.0;
    for (int j = 1; j <= p[i - 1 + K]; j++)
    {
      now3 = j * (1.0 / p[i - 1 + K]);
      now4 += now3;
    }
    E[i - 1 + K] = now4;
    ans += E[i - 1 + K];
    res = max(res, ans);
  }
  cout << fixed << setprecision(10) << res << endl;
}
