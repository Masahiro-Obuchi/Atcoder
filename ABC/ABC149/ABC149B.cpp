#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int A, B, K;
  cin >> A >> B >> K;
  long long int ans = 0;
  if (K <= A)
  {
    A -= K;
    cout << A << " " << B << endl;
  }
  else if (K > A && K <= (A + B))
  {
    K -= A;
    B -= K;
    cout << 0 << " " << B << endl;
  }
  else if (K > A + B)
  {
    cout << 0 << " " << 0 << endl;
  }
}
