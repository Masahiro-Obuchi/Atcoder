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

void solve()
{
  string s;
  cin >> s;
  int ans = s.size() - 2;
  int maxNum = 0;
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      int cnt = 0;
      string tmp = to_string(i) + to_string(j);
      if (i != j)
      {
        bool exist = false;
        for (int k = 0; k < s.size(); k++)
        {
          if (s[k] == to_string(i)[0])
            exist = true;
          else if (exist && s[k] == to_string(j)[0])
          {
            cnt++;
            exist = false;
          }
        }
        maxNum = max(maxNum, cnt * 2);
      }
      else
      {
        // cerr << to_string(i)[0] << endl;
        for (int k = 0; k < s.size(); k++)
        {
          if (s[k] == to_string(i)[0])
            cnt++;
        }
        maxNum = max(maxNum, cnt);
      }
    }
  }
  int n = s.size();
  cout << min(ans, n - maxNum) << endl;
}
// s.substrで比較していくと連続したやつしか見れないので1文字目が出たかをboolで持ってiと同じ奴が出たらtrue, trueの状態でjと同じ奴が出たらcntを+する．cnt * 2のmaxを求める．iとjが同じ場合は各文字iと同じものがあればcntを+する．最後にmin(n - 2, n - maxNum)をする

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    solve();
  }
  return 0;
}
