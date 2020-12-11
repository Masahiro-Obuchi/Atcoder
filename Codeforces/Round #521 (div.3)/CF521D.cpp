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

vector<int> t;

bool check(int x, int n, int k, vector<int> &s, vector<int> &cnt)
{
  t.clear();
  for (int i = 0; i <= 200000; i++)
  {
    int need = min(cnt[i] / x, k - (int)t.size()); // x回操作を行わなければならないから　k - t.size()以上追加する必要はない
    for (int j = 0; j < need; j++)
    {
      t.push_back(i);
    }
  }
  return (int)t.size() == k; // tのサイズがk以上だったらおけ　（この場合は==k）
}

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> s(n);
  for (auto &it : s)
    cin >> it;
  vector<int> cnt(200010);
  for (int i = 0; i < n; i++)
    cnt[s[i]]++;

  int left = 1, right = n;
  while (left + 1 < right)
  {
    int mid = (left + right) / 2;
    if (check(mid, n, k, s, cnt))
      left = mid;
    else
      right = mid;
  }
  if (!check(right, n, k, s, cnt))
    check(left, n, k, s, cnt);
  for (auto it : t)
    cout << it << " ";
  cout << endl;
  return;
}
// 二分探索を行う．操作を行うことが出来る回数をval回とすると，当然val - 1回も出来るから
//

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
