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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (auto &it : A)
    cin >> it;
  vector<int> cnt(1000010);
  for (int i = 0; i < N; i++)
    cnt[A[i]]++;
  int ans = 0;
  for (int i = 0; i < N; i++)
  {
    vector<ll> div = divisor(A[i]);
    bool exist = false;
    if (cnt[A[i]] != 1)
      exist = true;
    for (auto it : div)
    {
      if (it == A[i])
        continue;
      if (cnt[it] > 0)
        exist = true;
    }
    if (!exist)
      ans++;
  }
  cout << ans << endl;
  return 0;
}
