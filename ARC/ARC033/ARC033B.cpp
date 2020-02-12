#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int NA, NB;
  cin >> NA >> NB;
  vector<long long> A(NA);
  for (int i = 0; i < NA; i++)
    cin >> A[i];
  vector<long long> B(NB);
  for (int i = 0; i < NB; i++)
    cin >> B[i];
  double ans = 0.0;
  set<long long> aorb;
  for (int i = 0; i < NA; i++)
    aorb.insert(A[i]);
  for (int i = 0; i < NB; i++)
    aorb.insert(B[i]);
  map<long long, long long> aandb;
  for (int i = 0; i < NA; i++)
  {
    aandb[A[i]]++;
  }
  for (int i = 0; i < NB; i++)
  {
    aandb[B[i]]++;
  }
  long long num = 0;
  for (auto itr = aandb.begin(); itr != aandb.end(); itr++)
  {
    if (itr->second >= 2)
      num++;
  }
  ans = (double)num / (double)aorb.size();
  cout << fixed << setprecision(10) << ans << endl;
}
