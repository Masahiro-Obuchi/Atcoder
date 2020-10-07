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
  string s;
  cin >> s;
  for (int i = 0; i < s.size() - 1; i++)
  {
    if (i != s.size() - 2)
    {
      if (s[i] == s[i + 2])
      {
        cout << i + 1 << " " << i + 3 << endl;
        return 0;
      }
    }
    if (s[i] == s[i + 1])
    {
      cout << i + 1 << " " << i + 2 << endl;
      return 0;
    }
  }
  cout << -1 << " " << -1 << endl;
  return 0;
}

// 2文字連続かa?aのようになってればアンバランスなのでok.そうなってなければアンバランスにはなりえないのでアウト．(4文字以上を考えるとa??aのような場合アンバランスではなくaa??のような場合，左2文字をみればアンバランスな文字列になっているから)
