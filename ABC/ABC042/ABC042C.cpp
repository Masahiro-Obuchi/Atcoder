#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> D(K);
  for (int i = 0; i < K; i++)
    cin >> D[i];
  while (1)
  {
    bool ok = true;
    string NS = to_string(N);
    for (int i = 0; i < NS.size(); i++)
    {
      for (int j = 0; j < D.size(); j++)
      {
        if (NS[i] == D[j] + '0')
          ok = false;
      }
    }
    if (ok)
      break;
    else
      N++;
  }
  cout << N << endl;
  return 0;
}
