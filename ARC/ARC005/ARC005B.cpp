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
  int x, y;
  cin >> x >> y;
  x--, y--;
  string W;
  cin >> W;
  vector<string> Wvec = {"R", "L", "U", "D", "RU", "RD", "LU", "LD"};
  vector<vector<char>> c(9, vector<char>(9));
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      cin >> c[i][j];
    }
  }
  string ans;
  int nowY = y, nowX = x;
  if (W == "R" || W == "L" || W == "U" || W == "D")
  {
    bool change = false;
    if (W == "R")
    {
      for (int i = 0; i < 4; i++)
      {
        ans += c[nowY][nowX];
        if (change)
          nowX--;
        else
          nowX++;
        if (nowX == 9)
        {
          change = true;
          nowX = 7;
        }
        cerr << ans << endl;
      }
    }
    else if (W == "L")
    {
      for (int i = 0; i < 4; i++)
      {
        ans += c[nowY][nowX];
        if (change)
          nowX++;
        else
          nowX--;
        if (nowX == -1)
        {
          change = true;
          nowX = 1;
        }
      }
    }
    else if (W == "U")
    {
      for (int i = 0; i < 4; i++)
      {
        ans += c[nowY][nowX];
        if (change)
          nowY++;
        else
          nowY--;
        if (nowY == -1)
        {
          change = true;
          nowY = 1;
        }
      }
    }
    else
    {
      for (int i = 0; i < 4; i++)
      {
        ans += c[nowY][nowX];
        if (change)
          nowY--;
        else
          nowY++;
        if (nowY == 9)
        {
          change = true;
          nowY = 7;
        }
        cerr << ans << endl;
      }
    }
  }
  else
  {
    bool change1 = false;
    bool change2 = false;
    bool change3 = false;
    if (W == "RU")
    {
      for (int i = 0; i < 4; i++)
      {
        ans += c[nowY][nowX];
        if (change1)
        {
          nowY++, nowX--;
        }
        else if (change2 && change3)
        {
          nowY++, nowX--;
        }
        else if (change2)
        {
          nowY--, nowX--;
        }
        else if (change3)
        {
          nowY++, nowX++;
        }
        else
        {
          nowY--, nowX++;
        }
        if (nowY == -1 && nowX == 9)
        {
          change1 = true;
          nowY = 1, nowX = 7;
        }
        else if (nowX == 9)
        {
          change2 = true;
          nowX = 7;
        }
        else if (nowY == -1)
        {
          change3 = true;
          nowY = 1;
        }
      }
    }
    else if (W == "RD")
    {
      for (int i = 0; i < 4; i++)
      {
        ans += c[nowY][nowX];
        if (change1)
        {
          nowY--, nowX--;
        }
        else if (change2 && change3)
        {
          nowY--, nowX--;
        }
        else if (change2)
        {
          nowY++, nowX--;
        }
        else if (change3)
        {
          nowY--, nowX++;
        }
        else
        {
          nowY++, nowX++;
        }
        if (nowY == 9 && nowX == 9)
        {
          change1 = true;
          nowY = 7, nowX = 7;
        }
        else if (nowX == 9)
        {
          change2 = true;
          nowX = 7;
        }
        else if (nowY == 9)
        {
          change3 = true;
          nowY = 7;
        }
        cerr << ans << endl;
      }
    }
    else if (W == "LU")
    {
      for (int i = 0; i < 4; i++)
      {
        ans += c[nowY][nowX];
        if (change1)
        {
          nowY++, nowX++;
        }
        else if (change2 && change3)
        {
          nowY++, nowX++;
        }
        else if (change2)
        {
          nowY--, nowX++;
        }
        else if (change3)
        {
          nowY++, nowX--;
        }
        else
        {
          nowY--, nowX--;
        }
        if (nowY == -1 && nowX == -1)
        {
          change1 = true;
          nowY = 1, nowX = 1;
        }
        else if (nowX == -1)
        {
          change2 = true;
          nowX = 1;
        }
        else if (nowY == -1)
        {
          change3 = true;
          nowY = 1;
        }
      }
    }
    else
    {
      for (int i = 0; i < 4; i++)
      {
        ans += c[nowY][nowX];
        if (change1)
        {
          nowY--, nowX++;
        }
        else if (change2 && change3)
        {
          nowY--, nowX++;
        }
        else if (change2)
        {
          nowY++, nowX++;
        }
        else if (change3)
        {
          nowY--, nowX--;
        }
        else
        {
          nowY++, nowX--;
        }
        if (nowY == 9 && nowX == -1)
        {
          change1 = true;
          nowY = 7, nowX = 1;
        }
        else if (nowX == -1)
        {
          change2 = true;
          nowX = 1;
        }
        else if (nowY == 9)
        {
          change3 = true;
          nowY = 7;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
