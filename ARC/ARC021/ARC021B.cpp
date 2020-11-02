#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define PI 3.14159265358979
using namespace std;
using ll = long long;
using P = pair<int, int>;
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
// using Graph = vector<vector<Edge>>;
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int L;
  cin >> L;
  vector<ll> B(L);
  for (auto &it : B)
    cin >> it;
  ll xorsum = B[0];
  for (int i = 1; i < L - 1; i++)
  {
    xorsum ^= B[i];
  }
  if (B[L - 1] != xorsum)
  {
    cout << -1 << endl;
    return 0;
  }
  else
  {
    vector<ll> A(L);
    A[0] = 0;
    ll Bsum = B[0];
    for (int i = 1; i < L; i++)
    {
      A[i] = A[0] ^ Bsum;
      Bsum ^= B[i];
    }
    for (auto &it : A)
      cout << it << endl;
  }
  return 0;
}

// BN = B1^B2^...^BN-1が成立しないならば解なし　成立するならばA1 = 0とおいて順に計算(Ai = A1^B1^B2^...^Bi-1)
