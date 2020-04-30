#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

vector<vector<int>> d(10, vector<int>(10, 100000));

void warshallFloyd(int n)
{
  for (int k = 0; k < n; k++) // 経由する頂点
  {
    for (int i = 0; i < n; i++) // 始点
    {
      for (int j = 0; j < n; j++) // 終点
      {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]); // 距離
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    int A, B;
    cin >> A >> B;
    A--, B--;
    d[A][B] = 1, d[B][A] = 1;
  }

  for (int i = 0; i < N; i++)
    d[i][i] = 0;
  warshallFloyd(N);
  for (int i = 0; i < N; i++)
  {
    int cnt = 0;
    for (int j = 0; j < N; j++)
    {
      if (d[i][j] == 2)
        cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}

//　ワーシャルフロイド法　頂点間の最短距離を求めることが出来る
