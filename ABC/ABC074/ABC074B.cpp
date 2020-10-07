#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  int K;
  cin >> K;
  vector<int> xvec(N);
  for (auto &x : xvec)
  {
    cin >> x;
  }
  int sum = 0;
  for (int i = 0; i < N; i++)
  {
    sum += 2 * min(abs(xvec[i] - 0), abs(xvec[i] - K));
  }
  cout << sum << endl;
}
