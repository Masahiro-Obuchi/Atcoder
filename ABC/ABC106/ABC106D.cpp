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
using Graph = vector<vector<Edge>>;
// using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<int> L(M), R(M);
  // グリッド
  vector<vector<int>> a(N, vector<int>(N));
  for (int i = 0; i < M; i++)
  {
    cin >> L[i] >> R[i];
    L[i]--, R[i]--;
    a[L[i]][R[i]]++;
  }

  cerr << "grid" << endl;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cerr << a[i][j] << " ";
    }
    cerr << endl;
  }

  // 二次元累積和の構築
  vector<vector<int>> s(N + 1, vector<int>(N + 1));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + a[i][j];
    }
  }

  cerr << "sum" << endl;
  for (int i = 0; i < N + 1; i++)
  {
    for (int j = 0; j < N + 1; j++)
    {
      cerr << s[i][j] << " ";
    }
    cerr << endl;
  }

  // 各クエリの計算((x1, x2], * (y1, y2]の長方形区間の和)
  for (int i = 0; i < Q; i++)
  {
    int p, q;
    cin >> p >> q;
    p--, q--;
    cout << s[q + 1][q + 1] - s[p][q + 1] - s[q + 1][p] + s[p][p] << endl;
  }
}

// 各列車の走る区間は(Lj, Rj)でありクエリは(pi, qi)であるようにそれぞれについて「区間の左端」，「区間の右端」の2つの要素しかないので2次元座標をしてみなすことにする．xl,rを区間[l, r]を走る列車の個数とするとクエリ(p, q)に対して求めたい値はxp,p + xp,p+1 + ... + xp,q + xp+1,q + xq,qとなる．すなわち2次元座標で囲まれた面積となる．累積和を使って求める
// 二次元累積和を使う　ある面積を求めたいとき四つの面積の足し引きで求めることが出来る　そして各々の面積sはs[x + 1][y + 1]を求めたいときs[x + 1][y]，s[x][y + 1]が求められているとするとs[x + 1][y + 1] = s[x + 1][y] + s[x][y + 1] - s[x][y] + a[x][y]で求めることが出来る．
