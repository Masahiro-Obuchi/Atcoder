#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<string> S(N);
  vector<int> T(N);
  int all = 0;
  for (int i = 0; i < N; i++)
  {
    cin >> S[i];
    int t;
    cin >> t;
    T[i] = t;
    all += t;
  }
  string X;
  cin >> X;
  int num = -1;
  for (int i = 0; i < N; i++)
  {
    if (S[i] == X)
    {
      num = i;
      break;
    }
  }
  int sum = 0;
  for (int i = 0; i <= num; i++)
  {
    sum += T[i];
  }
  int ans = all - sum;
  cout << ans << endl;
}
