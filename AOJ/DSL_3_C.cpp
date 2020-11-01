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
  int N, Q;
  cin >> N >> Q;
  vector<ll> a(N);
  for (auto &it : a)
    cin >> it;
  vector<ll> x(Q);
  for (auto &it : x)
    cin >> it;

  for (int i = 0; i < Q; i++)
  {
    ll ans = 0;
    int right = 0;
    ll sum = 0;
    for (int left = 0; left < N; left++)
    {
      while (right < N && sum + a[right] <= x[i])
      {
        sum += a[right];
        right++;
      }
      ans += right - left;
      if (left == right)
        right++;
      else
        sum -= a[left];
    }
    cout << ans << endl;
  }
  return 0;
}
