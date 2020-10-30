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

bool check(long double x, vector<long double> &w, vector<long double> &p, int N, int K)
{
  vector<long double> y(N);
  for (int i = 0; i < N; i++)
  {
    y[i] = w[i] * (p[i] - x);
  }
  sort(y.begin(), y.end(), greater<long double>());
  long double sum = 0.0;
  for (int i = 0; i < K; i++)
  {
    sum += y[i];
  }
  return sum >= 0;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<long double> w(N), p(N);
  for (int i = 0; i < N; i++)
    cin >> w[i] >> p[i];

  long double left = 0.0, right = 110;
  for (int i = 0; i < 40; i++)
  {
    long double mid = (left + right) / 2.0;
    if (check(mid, w, p, N, K))
      left = mid;
    else
      right = mid;
  }
  cout << fixed << setprecision(12) << left << endl;
  return 0;
}

// 食塩水の濃度:=食塩/（食塩＋水）
// 連続
