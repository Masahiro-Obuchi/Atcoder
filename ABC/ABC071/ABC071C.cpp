#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end(), greater<int>());
  vector<long long int> V;
  for (int i = 0; i < N - 1; i++)
  {
    if (A.at(i) == A.at(i + 1))
    {
      V.push_back(A.at(i));
      i++;
    }
  }
  if ((int)V.size() < 2)
    cout << 0 << endl;
  else
    cout << V[0] * V[1] << endl;
}
