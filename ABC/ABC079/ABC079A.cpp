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
  string N;
  cin >> N;
  if ((N[0] == N[1] && N[1] == N[2]) || (N[1] == N[2] && N[2] == N[3]))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
