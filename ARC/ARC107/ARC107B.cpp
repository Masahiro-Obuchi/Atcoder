#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
/*
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
*/
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  ll ans = 0;
  if (K >= 0)
  {
    for (ll i = 2; i <= 2 * N; i++)
    {
      ll cd = i - K;
      if (cd < 2)
        continue;
      ll tmp1 = 0, tmp2 = 0;
      if (i % 2 == 0)
      {
        if (N - i / 2 >= 0)
        {
          tmp1 += (min(i - 1, (ll)N) - i / 2) * 2;
          tmp1++;
        }
      }
      else
      {
        if (N - i / 2 >= 0)
        {
          tmp1 += (min(i - 1, (ll)N) - i / 2) * 2;
        }
      }
      if (cd % 2 == 0)
      {
        if (N - cd / 2 >= 0)
        {
          tmp2 += (min(cd - 1, (ll)N) - cd / 2) * 2;
          tmp2++;
        }
      }
      else
      {
        if (N - cd / 2 >= 0)
        {
          tmp2 += (min(cd - 1, (ll)N) - cd / 2) * 2;
        }
      }
      ans += tmp1 * tmp2;
    }
  }
  else
  {
    for (ll i = 2; i <= 2 * N; i++)
    {
      ll ab = K + i;
      if (ab < 2)
        continue;
      ll tmp1 = 0, tmp2 = 0;
      if (i % 2 == 0)
      {
        if (N - i / 2 >= 0)
        {
          tmp1 += (min(i - 1, (ll)N) - i / 2) * 2;
          tmp1++;
        }
      }
      else
      {
        if (N - i / 2 >= 0)
        {
          tmp1 += (min(i - 1, (ll)N) - i / 2) * 2;
        }
      }
      if (ab % 2 == 0)
      {
        if (N - ab / 2 >= 0)
        {
          tmp2 += (min(ab - 1, (ll)N) - ab / 2) * 2;
          tmp2++;
        }
      }
      else
      {
        if (N - ab / 2 >= 0)
        {
          tmp2 += (min(ab - 1, (ll)N) - ab / 2) * 2;
        }
      }
      // cerr << "i: " << i << "tmp1: " << tmp1 << "  tmp2: " << tmp2 << endl;
      ans += tmp1 * tmp2;
    }
  }
  cout << ans << endl;
  return 0;
}
// 整数N, Kが与えられる．2つの整数の組(a, b)であって1<=a,b<=Nを満たすものの個数f(N, K) f(N, K) = min(K - 1, 2*N+1-K)
