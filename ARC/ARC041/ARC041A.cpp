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
//using Graph = vector<vector<Edge>>;
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;
const double PI = acos(-1.0);

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

const int MOD = 1000000007;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<int> a(M);
  for (auto &it : a)
    cin >> it;
  vector<bool> used(N + 1, false);
  vector<int> ans;
  for (auto &it : a)
    ans.push_back(it);
  for (int i = ans.size() - 1; i >= 0; i--)
  {
    if (!used[ans[i]])
    {
      cout << ans[i] << endl;
      used[ans[i]] = true;
    }
  }
  vector<int> b(N);
  iota(b.begin(), b.end(), 1);
  for (auto &it : b)
  {
    if (!used[it])
      cout << it << endl;
  }
  return 0;
}
