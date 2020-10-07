#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  long long int ans = 0;
  vector<string> S(N);
  for (auto &v : S)
  {
    cin >> v;
  }
  vector<long long int> MARCH(5);
  for (auto &v : S)
  {
    if (v.at(0) == 'M')
      MARCH.at(0)++;
    else if (v.at(0) == 'A')
      MARCH.at(1)++;
    else if (v.at(0) == 'R')
      MARCH.at(2)++;
    else if (v.at(0) == 'C')
      MARCH.at(3)++;
    else if (v.at(0) == 'H')
      MARCH.at(4)++;
  }
  vector<int> P = {0, 0, 0, 0, 0, 0, 1, 1, 1, 2};
  vector<int> Q = {1, 1, 1, 2, 2, 3, 2, 2, 3, 3};
  vector<int> R = {2, 3, 4, 3, 4, 4, 3, 4, 4, 4};
  for (int i = 0; i < 10; i++)
  {
    ans += MARCH.at(P.at(i)) * MARCH.at(Q.at(i)) * MARCH.at(R.at(i));
  }
  cout << ans << endl;
}
