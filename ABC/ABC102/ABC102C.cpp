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

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<ll> A(N);
  for (auto &it : A)
    cin >> it;
  vector<ll> B(N);
  for (int i = 0; i < N; i++)
  {
    B[i] = A[i] - (i + 1);
  }
  sort(B.begin(), B.end());
  int b;
  int half = N / 2;
  if (N % 2 == 0)
  {
    b = (B[half - 1] + B[half]) / 2;
  }
  else
  {
    b = B[half];
  }
  ll ans = 0;
  for (int i = 0; i < N; i++)
  {
    ans += abs(A[i] - (b + i + 1));
  }
  cout << ans << endl;
  return 0;
}

// abs(Ai - (b + i))を加算していくことからabs(Ai - i - b) 同じ変数を持つAiとiをまとめてBi = Ai - iと定義すれば，問題は自由に整数bを選び，abs(Bi - b)の総和を最小化する問題となる．よってBiをソートして中央値を求め実際に答えを計算すればよい．
