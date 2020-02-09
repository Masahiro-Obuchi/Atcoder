#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int N;
  cin >> N;
  vector<int> T(N);
  for (int i = 0; i < N; i++)
    cin >> T[i];
  sort(T.begin(), T.end());
  cout << T[0] << endl;
}
