#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<ll> A(N), B(N), C(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];
  for (int i = 0; i < N; i++)
    cin >> B[i];
  for (int i = 0; i < N; i++)
    cin >> C[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  ll ans = 0;

  for (int j = 0; j < N; j++)
  {
    ll numA = lower_bound(A.begin(), A.end(), B[j]) - A.begin();
    ll numC = N - (upper_bound(C.begin(), C.end(), B[j]) - C.begin());
    ans += numA * numC;
  }

  cout << ans << endl;
  return 0;
}

// Ai < Bj < Ckなる組(i, j, k)を求める問題．jを固定すればAi < Bjなるiの数とBj < Ckなるkの数の個数の積となり1重ループで解くことが出来る．
// あるパーツを調べてlower_boundとupper_boundで条件を満たすパーツを調べる
// Aの使える個数はlower_bound(A.begin(), A.end(), B[j]) - A.begin()
// upper_boundはある値より初めて大きい値が出た時のイテレータを返す
