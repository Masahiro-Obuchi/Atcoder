#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> X(N);
  vector<int> X2(N);
  for (int i = 0; i < N; i++)
  {
    cin >> X.at(i);
  }
  X2 = X;
  sort(X2.begin(), X2.end());
  int median_1 = X2.at(N / 2 - 1);
  int median_2 = X2.at(N / 2);
  for (int i = 0; i < N; i++)
  {
    if (X.at(i) >= median_2)
      cout << median_1 << endl;
    else
      cout << median_2 << endl;
  }
}
