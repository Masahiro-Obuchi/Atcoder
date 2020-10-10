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
    ll weight;
    Edge(int t, ll w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
*/
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (auto &it : S)
    cin >> it;
  int ans = 0;
  for (int i = 0; i < H; i++)
  {
    for (int j = 1; j < W; j++)
    {
      if (S[i][j] == '.' && S[i][j - 1] == '.')
        ans++;
    }
  }
  for (int i = 1; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (S[i][j] == '.' && S[i - 1][j] == '.')
        ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
