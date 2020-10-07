#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> avec(N);
  for (auto &a : avec)
  {
    cin >> a;
  }
  sort(avec.begin(), avec.end(), greater<int>());
  int Alice = 0;
  int Bob = 0;
  for (int i = 0; i < avec.size(); i++)
  {
    if (i % 2 == 0)
    {
      Alice += avec[i];
    }
    else
      Bob += avec[i];
  }
  cout << Alice - Bob << endl;
}
