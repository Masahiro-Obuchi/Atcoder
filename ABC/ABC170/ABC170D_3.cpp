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
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &it : A)
    cin >> it;
  vector<int> cnt(1000010);
  for (auto it : A)
  {
    if (cnt[it] != 0)
    {
      cnt[it] = 2;
      continue; // それ自身の倍数は既にインクリメントされていて約数が存在していることが確定しているためそれ自身の倍数の処理はスキップ
      // 自分自身はインクリメントしておかないと重複していることの判定が出来ないため重複しているという意味でcnt[it] = 2にしておく
    }
    for (int i = it; i < 1000010; i += it)
      cnt[i]++; // それ自身の倍数をインクリメントしていく
  }
  int ans = 0;
  for (auto it : A)
  {
    if (cnt[it] == 1)
      ans++;
  }
  cout << ans << endl;
  return 0;
}
