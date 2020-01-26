
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main()
{
  long long int H;
  cin >> H;
  long long int cnt = 0;
  while (H > 0)
  {
    H /= 2;
    cnt++;
  }
  long long ans = (long long)pow(2, cnt + 1) - 1;
  cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main()
{
  long long int N, K;
  cin >> N >> K;
  vector<long long> H(N);
  for (int i = 0; i < N; i++)
    cin >> H[i];
  sort(H.begin(), H.end(), greater<long long>());
  long long int cnt = 0;
  for (int i = K; i < N; i++)
    cnt += H[i];
  cout << cnt << endl;
}
