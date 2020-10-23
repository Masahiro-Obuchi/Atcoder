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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<string> b(N);
  for (auto &it : b)
    cin >> it;
  vector<vector<int>> bint(N, vector<int>(M));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      bint[i][j] = b[i][j] - '0';
    }
  }
  vector<vector<int>> ans(N, vector<int>(M));
  for (int i = 1; i < N - 1; i++)
  {
    for (int j = 1; j < M - 1; j++)
    {
      int tmp = min(bint[i - 1][j], min(bint[i][j + 1], min(bint[i + 1][j], bint[i][j - 1])));
      ans[i][j] = tmp;
      bint[i - 1][j] -= tmp;
      bint[i][j + 1] -= tmp;
      bint[i + 1][j] -= tmp;
      bint[i][j - 1] -= tmp;
    }
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}

// 答え用の別配列を用意しておいて上下左右の最小値を記録していく．その後元々の配列の上下左右から記録した値を引いていく．
