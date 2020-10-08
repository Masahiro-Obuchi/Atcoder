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
  ll N, X, M;
  cin >> N >> X >> M;

  vector<int> ord(M, -1);
  vector<ll> rireki, syu;
  ll res = 0;
  for (int n = 0; n < N; n++)
  {
    if (ord[X] != -1)
    {
      int p = ord[X];
      for (int i = p; i < n; i++)
      {
        syu.push_back(rireki[i]);
      }
      break;
    }
    ord[X] = n;
    rireki.push_back(X);
    res += X;
    X = (X * X) % M;
    cerr << X << endl;
  }
  N -= rireki.size();
  if (N == 0)
  {
    cout << res << endl;
    return 0;
  }

  vector<ll> sum(syu.size() + 1, 0);
  for (int i = 0; i < syu.size(); i++)
    sum[i + 1] = sum[i] + syu[i];

  ll q = N / syu.size();
  ll r = N % syu.size();
  res += sum[syu.size()] * q + sum[r];
  cout << res << endl;
  return 0;
}
