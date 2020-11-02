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
  int n, c;
  cin >> n >> c;
  vector<int> a(n);
  for (auto &it : a)
    cin >> it;
  int ans = INT_INF;
  for (int i = 1; i <= 10; i++)
  {
    for (int j = 1; j <= 10; j++)
    {
      if (i == j)
        continue;
      int tmp = 0;
      vector<int> b = a;
      for (int k = 0; k < n; k++)
      {
        if (k % 2 == 0)
        {
          if (b[k] != i)
            tmp += c;
        }
        else
        {
          if (b[k] != j)
            tmp += c;
        }
      }
      ans = min(ans, tmp);
    }
  }
  cout << ans << endl;
  return 0;
}
