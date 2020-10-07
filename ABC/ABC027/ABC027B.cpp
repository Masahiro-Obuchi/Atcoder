#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  int sum = 0;
  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % a.size() != 0)
    cout << -1 << endl;
  else
  {
    int num = sum / a.size();
    int cnt = 0;
    int sum2 = 0;
    int island = 1;
    for (int i = 0; i < N - 1; i++)
    {
      sum2 += a[i];
      if (sum2 % island != 0 or sum2 / island != num)
      {
        cnt++;
        island++;
      }
      else
      {
        sum2 = 0;
        island = 1;
      }
    }
    cout << cnt << endl;
  }
}
