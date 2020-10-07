#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  double a = (1900 * M + 100 * (N - M)) * pow(0.5, M);
  double r = (1 - pow(0.5, M));
  long long int ans = (a * r / pow((1 - r), 2)) + a / (1 - r);
  cout << ans << endl;
}
