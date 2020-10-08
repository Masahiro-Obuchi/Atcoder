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
  int X, N;
  cin >> X >> N;
  if (N == 0)
  {
    cout << X << endl;
    return 0;
  }
  else
  {
    vector<int> a(105);
    for (int i = 0; i < N; i++)
    {
      int p;
      cin >> p;
      a[p]++;
    }
    int nearX = INT_INF;
    int ans = -1;
    for (int i = 0; i <= 101; i++)
    {
      if (!a[i])
      {
        int tmp = abs(X - i);
        if (tmp < nearX)
        {
          nearX = min(nearX, tmp);
          ans = i;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
