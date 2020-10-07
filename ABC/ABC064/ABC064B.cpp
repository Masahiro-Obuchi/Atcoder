#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> avec(N);
  for (auto &a : avec)
    cin >> a;
  sort(avec.begin(), avec.end());
  cout << avec[N - 1] - avec[0] << endl;
}
