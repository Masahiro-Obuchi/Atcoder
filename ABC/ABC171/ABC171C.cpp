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
  ll N;
  cin >> N;
  ll sum = 0;
  ll mul = 1;
  int digitsNum = 1;
  vector<ll> sum26(15);
  for (int i = 1; i < 15; i++)
  {
    mul *= 26;
    sum += mul;
    sum26[i] = sum;
    if (N <= sum)
    {
      digitsNum = i;
      break;
    }
  }
  ll k = N - sum26[digitsNum - 1];
  k--;
  cerr << k << endl;
  string ans;
  while (k > 0)
  {
    ans += (char)('a' + (k % 26));
    k /= 26;
  }
  while ((int)ans.size() < digitsNum)
  {
    ans += 'a';
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
