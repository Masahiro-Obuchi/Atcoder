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
  int N;
  cin >> N;
  vector<ll> A(N);
  for (auto &it : A)
    cin >> it;
  ll res = 0;
  int right = 0;
  int sum = 0; // AND 和
  for (int left = 0; left < N; left++)
  {
    while (right < N && (sum ^ A[right]) == (sum + A[right]))
    {
      sum += A[right];
      right++;
    }
    res += right - left;
    if (left == right)
      right++;
    else
    {
      sum -= A[left]; // A[left]を削除　(sum^=A[left]でも可)
    }
  }
  cout << res << endl;
  return 0;
}

// 基本的にxor和<=加算和が成り立つ．例えばx=10101,y=1001O(二進法)としたときxxory = 11100(1の位が消える), x + y = 11110(1の位が繰り上がる)という感じになる．x+yは繰り上がりが残るのに対してxxoryは1が被ると消えてしまう．そう考えるとxxory = x + y <=> 二進法におけるどの桁を見てもxとyのうちビットが立っているのは高々1個のみ．すなわち条件を満たす区間の部分区間も条件を満たす．-> 尺取り法を用いる
