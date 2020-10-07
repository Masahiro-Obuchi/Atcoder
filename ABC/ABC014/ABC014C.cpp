#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
//using Graph = vector<vector<Edge>>;
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;
const double PI = acos(-1.0);

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i] >> b[i];
  }
  vector<ll> imos(1000010, 0);
  for (int i = 0; i < n; i++)
  {
    imos[a[i]]++;
    imos[++b[i]]--;
  }
  for (int i = 1; i <= 1000000; i++)
  {
    imos[i] += imos[i - 1];
  }
  ll ans = 0;
  for (int i = 0; i <= 1000000; i++)
    ans = max(ans, imos[i]);
  cout << ans << endl;
  return 0;
}

// いもす法
