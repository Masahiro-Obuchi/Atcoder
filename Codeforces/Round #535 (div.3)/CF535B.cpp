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

vector<long long> divisor(long long n)
{
  vector<long long> ret;
  for (long long i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      ret.push_back(i);
      if (i * i != n)
        ret.push_back(n / i);
    }
  }
  sort(ret.begin(), ret.end()); // 昇順に並べる
  return ret;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> d(n);
  for (auto &it : d)
    cin >> it;
  multiset<int> st;
  for (int i = 0; i < n; i++)
    st.insert(d[i]);

  auto xitr = st.end();
  xitr--;
  int x = *xitr;
  vector<ll> div = divisor(x);
  for (auto it : div)
  {
    if (st.count(it))
    {
      st.erase(st.find(it));
    }
  }
  auto yitr = st.end();
  yitr--;
  int y = *yitr;
  cout << x << " " << y << endl;
  return;
}

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
