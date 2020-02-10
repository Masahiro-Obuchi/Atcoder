#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  long long N, M;
  cin >> N >> M;
  vector<pair<long long, long long>> p(N);
  for (int i = 0; i < N; i++)
  {
    int a, b;
    cin >> a >> b;
    p[i] = make_pair(a, b);
  }
  sort(p.begin(), p.end());
  long long ans = 0, cnt = 0;
  int i = 0;
  while (cnt < M)
  {
    ans += p[i].second * p[i].first;
    cnt += p[i].second;
    i++;
  }
  if (cnt == M)
    cout << ans << endl;
  else
  {
    int ex = cnt - M;
    ans -= ex * p[i - 1].first;
    cout << ans << endl;
  }
}
