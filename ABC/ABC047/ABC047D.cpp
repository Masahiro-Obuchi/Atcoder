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
  ll N, T;
  cin >> N >> T;
  vector<ll> A(N);
  for (auto &it : A)
    cin >> it;
  ll MIN = INF;
  ll diff = 0;
  ll cnt = 1;
  for (int i = 0; i < N; i++)
  {
    ll tmp = A[i] - MIN;
    if (tmp > diff)
    {
      diff = max(diff, tmp);
      cnt = 1;
    }
    else if (tmp == diff)
      cnt++;
    MIN = min(MIN, A[i]);
  }
  cout << cnt << endl;
  return 0;
}

// 尺取りじゃなくてシンプルに最小値を管理すればいい
// 今まで見てきた最小値との差が最大となるものをdiffとする．このdiffが最大になる場所を青木君は-1すればよい．現在のA[i]と最小値との差をtmpとするとdiffがtmpより大きい場合，cntを1にしてdiffを更新する．（高橋君は最も利益が得られる場所で売ろうとするから）またtmpがdiffと等しかった場合は青木君が-1しなければならない場所が増えるからcntを+1する．この操作を0～N-1まで繰り返すことによってO(N)で答えを求めることが出来る．
