#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, x;
  cin >> N >> x;
  vector<int> a(N);
  for (auto &ai : a)
  {
    cin >> ai;
  }
  long long int cnt = 0;

  if (a[0] > x)
  {
    cnt += a[0] - x;
    a[0] = x;
  }
  for (int i = 0; i < N - 1; i++)
  {
    long long int sum = a[i] + a[i + 1];
    if (sum > x)
    {
      cnt += sum - x;
      a[i + 1] = x - a[i];
    }
  }

  cout << cnt << endl;
}
