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

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<string> S(N);
  for (auto &it : S)
    cin >> it;
  int cnt = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = N - 1; j >= 0; j--)
    {
      if (S[i][j] == '.')
      {
        cnt++;
        for (int k = j; k >= 0; k--)
          S[i][k] = 'o';
        if (i + 1 < N)
        {
          for (int k = j; k < N; k++)
          {
            S[i + 1][k] = 'o';
          }
        }
      }
    }
  }
  cout << cnt << endl;
  return 0;
}

// 解説よりまだ塗られていないマスのうち，最も上にあるもののうち最も右にあるものに着目する．このとき，選んだマスより上にあるものと右にあるものは既に塗られているはず　ここで選んだマスを塗る方法を考えるとZ字の右上の角を選んだマスに合わせて塗る塗り方が他の塗り方より真にいいことが分かる．解法としては　まだ塗られていないマスのうち右上の物を探す．　そのマスにZ字の右上の角を合わせられるように塗る．を繰り返し，全部の，マスが塗られるまでに繰り返した回数を答えればよい．
// サンプルケースだけではなく他のある程度塗られた状態を考えて実験する．
