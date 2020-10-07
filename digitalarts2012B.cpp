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
  string c;
  cin >> c;
  int N = c.size();
  if (c == "a" || c == "zzzzzzzzzzzzzzzzzzzz")
    cout << "NO" << endl;
  else
  {
    if (N == 1)
    {
      c[0] -= 1;
      c += "a";
      cout << c << endl;
    }
    else
    {
      bool same = true;
      for (int i = 0; i < N; i++)
        if (c[i] != c[0])
          same = false;
      if (!same)
      {
        reverse(c.begin(), c.end());
        cout << c << endl;
      }
      else
      {
        bool plus = false;
        bool minus = false;
        bool allA = true;
        bool allZ = true;
        for (int i = 0; i < N; i++)
        {
          if (c[i] != 'a')
            allA = false;
          if (c[i] != 'z')
            allZ = false;
        }
        cerr << allA << "  " << allZ << endl;
        if (!allA && !allZ)
        {
          for (int i = 0; i < N; i++)
          {
            if (!plus && c[i] != 'a')
            {
              c[i] -= 1;
              plus = true;
            }
            else if (!minus && c[i] != 'z')
            {
              c[i] += 1;
              minus = true;
            }
          }
          cout << c << endl;
        }
        else
        {
          if (allA)
          {
            c.erase(0, 2);
            cerr << c << endl;
            c += "b";
            cout << c << endl;
          }
          else
          {
            c.erase(0, 1);
            cerr << c << endl;
            c += "a";
            c += "y";
            cout << c << endl;
          }
        }
      }
    }
  }
  return 0;
}
