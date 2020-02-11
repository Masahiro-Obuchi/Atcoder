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
  {
    int a;
    cin >> a;
    a--;
    A[i] = a;
  }
  vector<int> ans(N);
  for (int i = 0; i < N; i++)
  {
    ans[A[i]] = i + 1;
  }
  for (int i = 0; i < N; i++)
    cout << ans[i] << endl;
}
