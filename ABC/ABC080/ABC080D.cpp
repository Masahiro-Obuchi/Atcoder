#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

// Graph
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
// using Graph = vector<vector<int>>;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, C;
  cin >> N >> C;
  vector<vector<int>> imos(C + 1, vector<int>(100010, 0));
  for (int i = 0; i < N; i++)
  {
    int s, t, c;
    cin >> s >> t >> c;
    imos[c][s]++;
    imos[c][t + 1]--;
  }
  for (int i = 1; i <= C; i++)
  {
    for (int j = 1; j < 100010; j++)
    {
      imos[i][j] += imos[i][j - 1];
    }
  }
  int ans = 0;
  for (int j = 0; j < 100010; j++)
  {
    int cnt = 0;
    for (int i = 1; i <= C; i++)
    {
      if (imos[i][j])
        cnt++;
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}

// チャンネル数の録画機があると考える．
// 録画するチャンネルが同じ時刻に何個あるかを求めればよい　このとき，必要な情報は以下の通り．チャンネル1～Cについて時刻tに録画するチャンネルがあるかどうか　これは各チャンネルについてimos法を用いれば十分高速に求められる．imos法を用いて各チャンネルの各時刻における録画する番組の有無を求める．　時刻tにおいて録画する番組があるチャンネルの個数を求めてその最大値を答えとする．
