#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B, C;
  cin >> A >> B >> C;
  int K;
  cin >> K;
  int sum = A + B + C;
  int D = max(max(A, B), C);
  sum -= D;
  for (int i = 0; i < K; i++)
  {
    D *= 2;
  }
  sum += D;
  cout << sum << endl;
  return 0;
}
