#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++)
  {
    cin >> p[i];
  }
  int cnt = 0;
  for (int i = 1; i < n - 1; i++)
  {
    if (p[i] > p[i - 1] and p[i] < p[i + 1] or p[i] < p[i - 1] and p[i] > p[i + 1])
      cnt++;
  }
  cout << cnt << endl;
}
