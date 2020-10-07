
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
  double deg, dis;
  vector<string> str = {"N",
                        "NNE",
                        "NE",
                        "ENE",
                        "E",
                        "ESE",
                        "SE",
                        "SSE",
                        "S",
                        "SSW",
                        "SW",
                        "WSW",
                        "W",
                        "WNW",
                        "NW",
                        "NNW",
                        "N"};
  vector<double> disTable = {0.2,
                             1.5,
                             3.3,
                             5.4,
                             7.9,
                             10.7,
                             13.8,
                             17.1,
                             20.7,
                             24.4,
                             28.4,
                             32.6,
                             200.0};
  int W;
  cin >> deg >> dis;
  deg /= 10;
  dis /= 60;
  dis = round(dis * 10) / 10;

  for (int i = 0; i < 13; i++)
  {
    if (dis <= disTable[i])
    {
      W = i;
      break;
    }
  }

  double cur = 11.25;
  int idx;

  if (W == 0)
  {
    cout << "C"
         << " " << 0 << endl;
    return 0;
  }
  else
  {
    for (int i = 0; i < 17; i++)
    {
      if (deg < cur)
      {
        idx = i;
        break;
      }
      cur += 22.5;
    }
  }
  cout << str[idx] << " " << W << endl;
  return 0;
}
