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

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cnt(1000010);
  ll sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    cnt[a[i]]++;
    sum += a[i];
  }

  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    sum -= a[i];
    cnt[a[i]]--;
    if (sum % 2 == 0 && sum / 2 <= 1000000 && cnt[sum / 2] > 0)
      ans.push_back(i);
    sum += a[i];
    cnt[a[i]]++;
  }

  cout << ans.size() << endl;
  for (auto it : ans)
  {
    cout << it + 1 << " ";
  }
  cout << endl;
}
// 和がそれ以外の要素になるということはsum/2が存在するということ
// a1 + a2 + a3 + ... + am (=sum / 2) al (=sum/2)という構造になっている

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  t = 1;
  for (int i = 0; i < t; i++)
  {
    solve();
  }
  return 0;
}
