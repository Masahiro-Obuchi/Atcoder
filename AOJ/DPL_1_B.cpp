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

#define NMAX 105
#define WMAX 10005
#define DIAGONAL 1
#define TOP 0

struct Item
{
  int value, weight;
};

int N, W;
Item items[NMAX + 1];
int C[NMAX + 1][WMAX + 1], G[NMAX + 1][WMAX + 1];

void compute(int &maxValue, vector<int> &selection)
{
  for (int w = 0; w <= W; w++)
  {
    C[0][w] = 0;
    G[0][w] = DIAGONAL;
  }
  for (int i = 1; i <= N; i++)
    C[i][0] = 0;

  for (int i = 1; i <= N; i++)
  {
    for (int w = 1; w <= W; w++)
    {
      C[i][w] = C[i - 1][w];
      G[i][w] = TOP;
      if (items[i].weight > w)
        continue;
      if (items[i].value + C[i - 1][w - items[i].weight] > C[i - 1][w])
      {
        C[i][w] = items[i].value + C[i - 1][w - items[i].weight];
        G[i][w] = DIAGONAL;
      }
    }
  }

  maxValue = C[N][W];
  selection.clear();
  for (int i = N, w = W; i >= 1; i--)
  {
    if (G[i][w] == DIAGONAL)
    {
      selection.push_back(i);
      w -= items[i].weight;
    }
  }

  reverse(selection.begin(), selection.end());
}

void input()
{
  cin >> N >> W;
  for (int i = 1; i <= N; i++)
  {
    cin >> items[i].value >> items[i].weight;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int maxValue;
  vector<int> selection;
  input();
  compute(maxValue, selection);

  cout << maxValue << endl;
  return 0;
}

// i個目までの品物を考慮して大きさWのナップサックに入れる場合の価値の合計の最大値C[i][w]とする二次元配列
// C[i - 1][w - 品物iの重さ] + 品物iの価値，またはC[i - 1][w]の大きい方になる．1はこの時点で品物iを選択する．2.はこの時点で品物iを選択しない．ただし，1.の場合は品物iの重さが品物iの重さがwを超えない場合に限る．
