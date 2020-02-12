#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int N;
  cin >> N;
  vector<int> P(N), Q(N);
  for (int i = 0; i < N; i++)
    cin >> P[i];
  for (int i = 0; i < N; i++)
    cin >> Q[i];
  vector<int> v(N);
  iota(v.begin(), v.end(), 1);
  int i = 1;
  int a = -1, b = -1;
  do
  {
    bool A = true, B = true;
    for (int j = 0; j < N; j++)
    {
      if (v[j] != P[j])
        A = false;
      if (v[j] != Q[j])
        B = false;
    }
    if (A)
      a = i;
    if (B)
      b = i;
    i++;
  } while (next_permutation(v.begin(), v.end()));
  cout << abs(a - b) << endl;
}
