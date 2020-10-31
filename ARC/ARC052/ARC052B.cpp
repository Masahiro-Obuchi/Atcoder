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

double computeVolumeOfCone(const int &upper, const int &lower, const int &bottom, const int &top, const int &radius, const int &height)
{
  int xUpperBottom = min(top, upper);
  int xLowerBottom = max(bottom, lower);
  double tanTheta = (double)radius / (double)height;
  double rUpperBottom = (double)(top - xUpperBottom) * tanTheta;
  double rLowerBottom = (double)(top - xLowerBottom) * tanTheta;
  double v = PI * (rUpperBottom * rUpperBottom + rUpperBottom * rLowerBottom + rLowerBottom * rLowerBottom) * (xUpperBottom - xLowerBottom) / 3.0;
  return v;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<double> X(N), R(N), H(N);
  for (int i = 0; i < N; i++)
    cin >> X[i] >> R[i] >> H[i];
  for (int i = 0; i < Q; i++)
  {
    int A, B;
    cin >> A >> B;
    double ans = 0.0;
    for (int j = 0; j < N; j++)
    {
      if (!(X[j] + H[j] <= A || X[j] >= B))
      {
        ans += computeVolumeOfCone(B, A, X[j], X[j] + H[j], R[j], H[j]);
      }
    }
    cout << fixed << setprecision(10) << ans << endl;
  }
  return 0;
}

// 累積和を使うorシンプルにクエリごとにN個の円錐を全て見て範囲に含まれるものを足していく．制約からN<=100 Q<=10^5であるため後者でも十分に間に合う．
