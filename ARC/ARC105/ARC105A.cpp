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
  vector<ll> A(4);
  for (auto &it : A)
    cin >> it;

  ll all = 0;
  for (auto it : A)
    all += it;
  bool can = false;
  for (int bit = 0; bit < (1 << 4); bit++)
  {
    ll sum = 0;
    for (int i = 0; i < 4; i++)
    {
      if (bit & (1 << i))
        sum += A[i];
    }

    if (all - sum == sum)
      can = true;
  }

  if (can)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
