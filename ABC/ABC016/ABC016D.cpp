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

typedef struct Point
{
  double x, y;
} point;

bool intersect(point &a, point &b, point &c, point &d)
{
  double s, t;
  s = (a.x - b.x) * (c.y - a.y) - (a.y - b.y) * (c.x - a.x);
  t = (a.x - b.x) * (d.y - a.y) - (a.y - b.y) * (d.x - a.x);
  if (s * t > 0)
    return false;

  s = (c.x - d.x) * (a.y - c.y) - (c.y - d.y) * (a.x - c.x);
  t = (c.x - d.x) * (b.y - c.y) - (c.y - d.y) * (b.x - c.x);
  if (s * t > 0)
    return false;

  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  point A, B;
  cin >> A.x >> A.y >> B.x >> B.y;
  int N;
  cin >> N;
  vector<point> P(N);
  for (int i = 0; i < N; i++)
  {
    cin >> P[i].x >> P[i].y;
  }
  P.push_back(P[0]);
  int cnt = 0;
  for (int i = 1; i < N + 1; i++)
  {
    if (intersect(A, B, P[i - 1], P[i]))
      cnt++;
    cerr << intersect(A, B, P[i - 1], P[i]) << endl;
  }
  if (cnt == 2)
    cout << 2 << endl;
  else
    cout << (cnt / 2) + 1 << endl;
  return 0;
}

// 図形と線分が交わった数 / 2 + 1 (2の時は例外)
// 線分の交差判定アルゴリズム
