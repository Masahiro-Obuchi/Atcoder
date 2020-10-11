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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &it : a)
    cin >> it;

  ll ans = 0;
  map<int, int> mp1;
  for (int j = 0; j < n; j++)
  {
    map<int, int> mp2;
    for (int k = n - 1; k > j; k--)
    {
      int left = mp1[a[k]];
      int right = mp2[a[j]];
      ans += left * right;
      mp2[a[k]]++; // k < lであるから最後に加算する．
    }
    mp1[a[j]]++; // i < jであるから最後に加算する．
  }
  cout << ans << endl;
}

// jを左から1ずつ進め，それぞれのjにおいてkを右端から進める．外側にある数字の数を持っておく．1つ目のmapでjより左に出ているものを管理し，2つめのmapでkより左にある数字を管理．jより左にあるa[k]と等しいものの数をleft = mp1[a[k]]とし，kより右にあるa[j]と等しいものの数をright = mp2[a[j]]とする．各j, kにおいて求める数はleft * rightとなる．

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
