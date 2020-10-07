#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  double ans = 0;
  for (int i = 0; i < N; i++)
  {
    double x;
    string u;
    cin >> x >> u;
    if (u == "JPY")
      ans += x;
    else
    {
      ans += x * 380000.0;
    }
  }
  cout << ans << endl;
}
