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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  while (true)
  {
    cin >> n;
    if (n == 0)
      break;

    vector<int> imos(100010, 0);
    for (int i = 0; i < n; i++)
    {
      int left = 0, right = 0;
      string S1;
      cin >> S1;
      int h = S1[0] - '0';
      h *= 10;
      h += S1[1] - '0';
      left += h * 3600;
      int m = S1[3] - '0';
      m *= 10;
      m += S1[4] - '0';
      left += m * 60;
      int s = S1[6] - '0';
      s *= 10;
      s += S1[7];
      left += s;

      h = 0, m = 0, s = 0;
      string S2;
      cin >> S2;
      h = S2[0] - '0';
      h *= 10;
      h += S2[1] - '0';
      right += h * 3600;
      m = S2[3] - '0';
      m *= 10;
      m += S2[4] - '0';
      right += m * 60;
      s = S2[6] - '0';
      s *= 10;
      s += S2[7];
      right += s;
      imos[left]++;
      imos[right]--;
    }
    for (int i = 0; i < 100000; i++)
    {
      imos[i + 1] += imos[i];
    }

    int ans = 0;
    for (int i = 0; i <= 100000; i++)
    {
      ans = max(ans, imos[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
