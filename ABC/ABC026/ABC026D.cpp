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

long double f(long double A, long double B, long double C, long double t)
{
  long double PI = acos(-1);
  return A * t + B * sin(C * t * PI) - 100.0;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long double A, B, C;
  cin >> A >> B >> C;
  long double left = 0.0, right = 10e4;
  long double t = (left + right) / 2.0;
  while (abs(f(A, B, C, t)) > 10e-7)
  {
    t = (left + right) / 2.0;
    if (f(A, B, C, t) > 0.0)
      right = t;
    else
      left = t;
  }
  cout << fixed << setprecision(12) << t << endl;
  return 0;
}
