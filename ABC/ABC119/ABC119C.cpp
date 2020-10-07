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

int N, A, B, C;
vector<int> l;

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

ll rec(int i, int a, int b, int c)
{
  if (i == N)
  {
    if (!a || !b || !c)
      return INF;
    return abs(a - A) + abs(b - B) + abs(c - C);
  }

  ll res = rec(i + 1, a, b, c); // 今ある竹を使用しない場合

  // A, B, Cに使う場合
  // (a ? 10 : 0)とかは最初の1本目は合体コストなし，2本目から10かかることを意味する
  chmin(res, rec(i + 1, a + l[i], b, c) + (a ? 10 : 0)); // 各場合についてresと比較していく
  chmin(res, rec(i + 1, a, b + l[i], c) + (b ? 10 : 0));
  chmin(res, rec(i + 1, a, b, c + l[i]) + (c ? 10 : 0));
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> A >> B >> C;
  l.resize(N);
  for (auto &it : l)
    cin >> it;
  cout << rec(0, 0, 0, 0) << endl;
  return 0;
}

// +1や-1を行うのは合体した後でよい．
// 各竹に対してAに使う，Bに使う，Cに使う，使わないの4つのパターンがあり，この全てのパターンを試す(4^N通り)ただし長さAの竹の材料，長さBの竹の材料，長さCの竹の材料がそれぞれ一本以上必要でこれを満たさない竹の扱い方は棄却する．全探索はdfsを使って行う．bit全探索でも可能
// int i, int a, int b, int c a: その時点でのAに採用した竹の長さの総和 B: その時点でのBに採用した竹の長さの総和 c: その時点でのCの採用した竹の長さの総和
