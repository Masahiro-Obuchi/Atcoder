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

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

vector<long long int> divisor(long long int n)
{
  vector<long long int> ret;
  for (long long int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      ret.push_back(i);
      if (i * i != n)
        ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  if (n == 2)
  {
    ll a, b;
    cin >> a >> b;
    ll ansMax = gcd(a, b);
    vector<ll> ans = divisor(ansMax);
    for (auto &it : ans)
      cout << it << endl;
  }
  else
  {
    ll a, b, c;
    cin >> a >> b >> c;
    ll ansMax = gcd(a, gcd(b, c));
    vector<ll> ans = divisor(ansMax);
    for (auto &it : ans)
      cout << it << endl;
  }
  return 0;
}
