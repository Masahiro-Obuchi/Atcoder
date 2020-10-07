
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
  cin >> deg >> dis;
  string dir;
  if (112.5 <= deg && deg < 337.5)
    dir = "NNE";
  else if (337.5 <= deg && deg < 562.5)
    dir = "NE";
  else if (562.5 <= deg && deg < 787.5)
    dir = "ENE";
  else if (787.5 <= deg && deg < 1012.5)
    dir = "E";
  else if (1012.5 <= deg && deg < 1237.5)
    dir = "ESE";
  else if (1237.5 <= deg && deg < 1462.5)
    dir = "SE";
  else if (1462.5 <= deg && deg < 1687.5)
    dir = "SSE";
  else if (1687.5 <= deg && deg < 1912.5)
    dir = "S";
  else if (1912.5 <= deg && deg < 2137.5)
    dir = "SSW";
  else if (2137.5 <= deg && deg < 2362.5)
    dir = "SW";
  else if (2362.5 <= deg && deg < 2587.5)
    dir = "WSW";
  else if (2587.5 <= deg && deg < 2812.5)
    dir = "W";
  else if (2812.5 <= deg && deg < 3037.5)
    dir = "WNW";
  else if (3037.5 <= deg && deg < 3262.5)
    dir = "NW";
  else if (3262.5 <= deg && deg < 3487.5)
    dir = "NNW";
  else
    dir = "N";

  double v = dis / 60.0;
  v = round(v * 10) / 10;
  int W = -1;
  if (0.0 <= v && v <= 0.2)
  {
    W = 0;
  }
  else if (0.2 < v && v <= 1.5)
  {
    W = 1;
  }
  else if (1.5 < v && v <= 3.3)
  {
    W = 2;
  }
  else if (3.3 < v && v <= 5.4)
  {
    W = 3;
  }
  else if (5.4 < v && v <= 7.9)
  {
    W = 4;
  }
  else if (7.9 < v && v <= 10.7)
  {
    W = 5;
  }
  else if (10.7 < v && v <= 13.8)
  {
    W = 6;
  }
  else if (13.8 < v && v <= 17.1)
  {
    W = 7;
  }
  else if (17.1 < v && v <= 20.7)
  {
    W = 8;
  }
  else if (20.7 < v && v <= 24.4)
  {
    W = 9;
  }
  else if (24.4 < v && v <= 28.4)
  {
    W = 10;
  }
  else if (28.4 < v && v <= 32.6)
  {
    W = 11;
  }
  else
  {
    W = 12;
  }
  if (W == 0)
    dir = 'C';
  cerr << v << endl;
  cout << dir << " " << W << endl;
  return 0;
}
