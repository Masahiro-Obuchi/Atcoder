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
// using Graph = vector<vector<Edge>>;
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
  vector<ll> T(N), A(N);
  for (int i = 0; i < N; i++)
    cin >> T[i] >> A[i];
  ll a = 0, b = 0;
  for (int i = 0; i < N; i++)
  {
    if (a <= T[i] && b <= A[i])
      a = T[i], b = A[i];
    else if (a > T[i] && b <= A[i])
    {
      a = ((a + T[i] - 1) / T[i]) * T[i];
      ll mul = a / T[i];
      b = A[i] * mul;
    }
    else if (a <= T[i] && b > A[i])
    {
      b = ((b + A[i] - 1) / A[i]) * A[i];
      ll mul = b / A[i];
      a = T[i] * mul;
    }
    else
    {
      ll mula = ((a + T[i] - 1) / T[i]) * T[i] / T[i];
      ll mulb = ((b + A[i] - 1) / A[i]) * A[i] / A[i];
      a = max(mula, mulb) * T[i], b = max(mula, mulb) * A[i];
    }
  }
  cout << a + b << endl;
  return 0;
}

// 両方とも小さかったら更新なし　片方だけ大きかったらT[i]またはA[i]をその値を超えるように掛けていく．何倍にするかは元のaまたはbのT[i]またはA[i]の切り上げ．もう片方も同じだけ掛ける．両方大きい場合は掛けるやつのmaxを取って掛ける．
