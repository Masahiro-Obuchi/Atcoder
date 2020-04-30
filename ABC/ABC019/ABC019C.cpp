#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<ll> a(N);
  for (auto &it : a)
    cin >> it;
  set<ll> st;
  ll ans = 0;
  for (int i = 0; i < N; i++)
  {
    while (a[i] % 2 == 0)
    {
      a[i] /= 2;
    }
    cerr << a[i] << endl;
    if (st.find(a[i]) == st.end())
    {
      ans++;
      st.insert(a[i]);
    }
  }
  cout << ans << endl;
  return 0;
}

// まず奇数にする．その奇数がセットの中に存在しなければansをインクリメントして，setにその奇数をinsertする．
