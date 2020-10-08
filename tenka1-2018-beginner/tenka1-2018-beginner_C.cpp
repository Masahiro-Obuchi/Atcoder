#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int N;
vector<string> ans;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<ll> A(N);
  for (auto &it : A)
    cin >> it;
  sort(A.begin(), A.end(), greater<ll>());

  if (N % 2 == 0)
  {
    ll res = 0;
    for (int i = 0; i < N / 2 - 1; i++)
      res += A[i] * 2;
    res += A[N / 2 - 1];
    res -= A[N / 2];
    for (int i = N / 2 + 1; i < N; i++)
      res -= A[i] * 2;
    cout << res << endl;
  }
  else
  {
    ll res1 = 0;
    for (int i = 0; i < N / 2 - 1; i++)
      res1 += A[i] * 2;
    res1 += A[N / 2 - 1] + A[N / 2];
    for (int i = N / 2 + 1; i < N; i++)
      res1 -= A[i] * 2;

    ll res2 = 0;
    for (int i = 0; i < N / 2; i++)
      res2 += A[i] * 2;
    res2 -= A[N / 2] + A[N / 2 + 1];
    for (int i = N / 2 + 2; i < N; i++)
      res2 -= A[i] * 2;
    cerr << res1 << " " << res2 << endl;
    cout << max(res1, res2) << endl;
  }
  return 0;
}

// ありうるパターンはp1 >= p2 <= p3>= ...かp1 <= p2 >= p3 <=...のいずれかになる．これら両方のパターンを試して大きい方を出力することにする．対称性より前者のパターンを考える．このとき，隣り合う項の差の絶対値の和は(p1 - p2) + (p3 - p2) + (p3 - p4) + (p5 - p4) + ...である．すなわち，各iに対し，piが最大化したい値に何回足されるかが決まる．たくさん足される値を大きく，たくさん引かれる値を小さくすることでこの値は最大化できるので各piにつく係数を見て大きい順に大きい要素を割り当てていけばよい
