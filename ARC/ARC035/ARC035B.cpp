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

const int MOD = 1000000007;

class mint
{
  ll x;

public:
  mint(ll x = 0) : x((x % MOD + MOD) % MOD) {}
  mint operator-() const
  {
    return mint(-x);
  }

  mint &operator+=(const mint &a)
  {
    if ((x += a.x) >= MOD)
      x -= MOD;
    return *this;
  }

  mint &operator-=(const mint &a)
  {
    if ((x += MOD - a.x) >= MOD)
      x -= MOD;
    return *this;
  }

  mint &operator*=(const mint &a)
  {
    (x *= a.x) %= MOD;
    return *this;
  }

  mint operator+(const mint &a)
  {
    mint res(*this);
    return res += a;
  }

  mint operator-(const mint &a)
  {
    mint res(*this);
    return res -= a;
  }

  mint operator*(const mint &a)
  {
    mint res(*this);
    return res *= a;
  }

  mint pow(ll t) const
  {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const
  {
    return pow(MOD - 2);
  }

  mint &operator/=(const mint &a)
  {
    return (*this) *= a.inv();
  }

  mint operator/(const mint &a)
  {
    mint res(*this);
    return res /= a;
  }

  friend ostream &operator<<(ostream &os, const mint &m)
  {
    os << m.x;
    return os;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<ll> T(N);
  for (auto &it : T)
    cin >> it;
  sort(T.begin(), T.end());
  ll passed = 0;
  ll penalty = 0;
  for (int i = 0; i < N; i++)
  {
    penalty += passed + T[i];
    passed += T[i];
    // cerr << penalty << " " << passed << endl;
  }
  cout << penalty << endl;
  mint ans = 1;
  vector<int> cnt(10010);
  for (int i = 0; i < N; i++)
  {
    cnt[T[i]]++;
  }
  for (int i = 0; i < 10010; i++)
  {
    if (cnt[i] >= 2)
    {
      mint tmp = 1;
      while (cnt[i] > 0)
      {
        tmp *= cnt[i];
        cnt[i]--;
      }
      ans *= tmp;
    }
  }
  cout << ans << endl;
  return 0;
}
