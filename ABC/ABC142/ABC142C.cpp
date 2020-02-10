#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  long long N, K, Q;
  cin >> N >> K >> Q;
  vector<long long> A(Q);
  for (int i = 0; i < Q; i++)
  {
    int a;
    cin >> a;
    a--;
    A[i] = a;
  }
  vector<long long> B(N);
  for (int i = 0; i < Q; i++)
  {
    B[A[i]]++;
  }
  for (int i = 0; i < N; i++)
  {
    if (K - Q + B[i] > 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
