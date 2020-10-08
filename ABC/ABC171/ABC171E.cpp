#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

// Graph
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
// using Graph = vector<vector<int>>;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<ll> a(N);
  for (auto &it : a)
    cin >> it;
  ll xorsum = a[0];
  for (int i = 1; i < N; i++)
    xorsum ^= a[i];
  vector<ll> ans(N);
  for (int i = 0; i < N; i++)
  {
    ans[i] = xorsum ^ a[i];
  }
  for (auto it : ans)
    cout << it << " ";
  cout << endl;
  return 0;
}
