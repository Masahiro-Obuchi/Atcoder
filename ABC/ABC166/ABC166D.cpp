#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll X;
  cin >> X;
  for (ll A = -200; A <= 200; A++)
  {
    for (ll B = -200; B <= 200; B++)
    {
      ll tmp = pow(A, 5) - pow(B, 5);
      if (X == tmp)
      {
        cout << A << " " << B << endl;
        return 0;
      }
    }
  }
  return 0;
}
