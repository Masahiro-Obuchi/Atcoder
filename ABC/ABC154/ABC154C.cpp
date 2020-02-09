#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  long long N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];
  set<long long> st;
  for (int i = 0; i < N; i++)
    st.insert(A[i]);
  if (st.size() == N)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
