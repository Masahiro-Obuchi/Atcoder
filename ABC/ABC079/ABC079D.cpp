#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W;
  cin >> H >> W;
  vector<vector<int>> c(10, vector<int>(10));
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
      cin >> c[i][j];
  }

  for (int k = 0; k < 10; k++)
  {
    for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 10; j++)
      {
        chmin(c[i][j], c[i][k] + c[k][j]);
      }
    }
  }

  ll res = 0;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      int A;
      cin >> A;
      if (A == -1)
        continue;
      res += c[A][1];
    }
  }
  cout << res << endl;
  return 0;
}

// 0, 2, 3, 4, 5, 6, 7, 8, 9それぞれに対して最短で1に進む方法を探索する．
// 初めに全ての数字において1に変えるのにかかるコストを計算しておく．これにはワーシャルフロイドが使える!!その後，全てのマスにおいて数字が書かれている場合の1への変更コストの和を求めればよい．
// ワーシャルフロイドは全頂点間の最短路長を求めることが出来る．
