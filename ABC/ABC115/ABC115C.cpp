#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<long long int> h(N);
  for (int i = 0; i < N; i++)
  {
    cin >> h.at(i);
  }
  long long int ans = 100000000000;
  sort(h.begin(), h.end());
  for (int i = 0; i < N - K + 1; i++)
  {
    long long int hmin, hmax;
    hmin = h.at(i);
    hmax = h.at(i + K - 1);
    ans = min(ans, hmax - hmin);
  }
  cout << ans << endl;
  return 0;
}
