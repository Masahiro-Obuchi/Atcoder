#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    int tmp = a[i];
    while (tmp % 2 == 0 or tmp % 3 == 2)
    {
      tmp--;
      sum++;
    }
  }
  cout << sum << endl;
}
