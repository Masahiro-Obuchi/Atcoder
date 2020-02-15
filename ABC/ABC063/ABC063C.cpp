#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int N;
  cin >> N;
  vector<int> s(N);
  for (int i = 0; i < N; i++)
    cin >> s[i];

  int ans = 0;
  for (int i = 0; i < N; i++)
  {
    ans += s[i];
  }
  if (ans % 10 != 0)
    cout << ans << endl;
  else
  {
    bool exist = false;
    sort(s.begin(), s.end(), greater<int>());
    for (int i = N - 1; i >= 0; i--)
    {
      if (s[i] % 10 != 0)
      {
        exist = true;
        ans -= s[i];
        break;
      }
    }
    if (exist)
      cout << ans << endl;
    else
    {
      cout << 0 << endl;
    }
  }
}

// bit全探索
