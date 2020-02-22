#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];
  bool ok = true;
  for (int i = 0; i < N; i++)
  {
    if (A[i] % 2 == 0)
    {
      if (!(A[i] % 3 == 0 or A[i] % 5 == 0))
        ok = false;
    }
  }
  if (ok)
    cout << "APPROVED" << endl;
  else
    cout << "DENIED" << endl;
}
