
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main()
{
  long long N;
  cin >> N;
  vector<long long> P(N);
  for (int i = 0; i < N; i++)
  {
    cin >> P[i];
  }
  long long cnt = 1;
  long long prev = P[0];
  for (int i = 1; i < N; i++)
  {
    if (P[i] <= prev)
      cnt++;
    prev = min(prev, P[i]);
  }
  cout << cnt << endl;
}
