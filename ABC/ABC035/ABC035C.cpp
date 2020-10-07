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
  int N, Q;
  cin >> N >> Q;
  vector<int> l(Q), r(Q);
  for (int i = 0; i < Q; i++)
  {
    cin >> l[i] >> r[i];
    l[i]--, r[i]--;
  }
  vector<int> imos(N + 1, 0);
  for (int i = 0; i < Q; i++)
  {
    imos[l[i]]++;
    imos[r[i] + 1]--;
  }
  for (int i = 1; i <= N; i++)
  {
    imos[i] += imos[i - 1];
    cerr << imos[i] << endl;
  }
  vector<int> field(N, 0);
  for (int i = 0; i < N; i++)
  {
    if (imos[i] % 2 != 0)
      field[i]++;
    cout << field[i];
  }
  cout << endl;
  return 0;
}

// 奇数回裏返されたら白になる　偶数回裏返されたら黒になる
// 各駒について裏返された回数だけ分かればよい
// いもす方は加算，構築，取得の3つの処理からなる
// 加算: 区間[l, r]にvだけ加算する．構築 : ある位置の値が求められるようにする．取得: ある位置の値を求める．
// 差分を覚えていく．累積和により構築する．加算処理ではl番目の値に+vして，r + 1番目の値に-vをする．構築処理ではi番目の値をi+1番目に加算する．
