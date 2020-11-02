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
  int N;
  cin >> N;
  vector<int> color(N);
  for (auto &it : color)
    cin >> it;
  int ans = 0;
  bool same = true;
  if (!(color[N - 1] == color[0] && color[0] == color[1]))
    same = false;
  if (!(color[N - 2] == color[N - 1] && color[N - 1] == color[0]))
    same = false;
  for (int i = 1; i < N - 1; i++)
  {
    if (!(color[i - 1] == color[i] && color[i] == color[i + 1]))
      same = false;
  }
  if (same)
    cout << -1 << endl;
  else
  {
    int cntMax = 2;
    int cnt = 2;
    int tmp = color[0];
    if (color[N - 1] == color[0] && color[0] == color[1])
      cnt++;
    for (int i = 1; i < N - 1; i++)
    {
      if (color[i - 1] == color[i] && color[i] == color[i + 1])
      {
        cnt++;
      }
      else
      {
        cntMax = max(cnt, cntMax);
        cnt = 2;
      }
    }
    if (color[N - 2] == color[N - 1] && color[N - 1] == color[0])
    {
      cnt++;
      if (color[N - 1] == color[0] && color[0] == color[1])
      {
        cnt++;
        for (int i = 1; i < N - 1; i++)
        {
          if (color[i - 1] == color[i] && color[i] == color[i + 1])
          {
            cnt++;
          }
          else
          {
            cntMax = max(cnt, cntMax);
            cerr << cntMax << endl;
            break;
          }
        }
      }
    }
    cntMax = max(cnt, cntMax);
    if (cntMax % 2 != 0)
      ans = cntMax / 2;
    else
      ans = cntMax / 2 - 1;
    cout << ans + 1 << endl;
  }
  return 0;
}

// 異なる色が隣り合う場所で切り1列にした方が処理しやすい．
