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
  int N;
  cin >> N;
  vector<int> x(N), y(N);
  for (int i = 0; i < N; i++)
    cin >> x[i] >> y[i];

  bool ok = false;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (i == j)
        continue;
      for (int k = 0; k < N; k++)
      {
        if (k == i || k == j)
          continue;
        if ((x[j] - x[i]) * (y[k] - y[i]) == (y[j] - y[i]) * (x[k] - x[i]))
        {
          // cerr << "i: " << i << "  j: " << j << "  k: " << k << endl;
          ok = true;
        }
      }
    }
  }
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
