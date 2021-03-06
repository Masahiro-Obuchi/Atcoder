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
  map<ll, int> mp;
  ll ans = 0;
  for (int j = 0; j < N; j++)
  {
    ans += mp[j - A[j]]; // まず答えに足す
    mp[j + A[j]]++;      // j + A[j] = XとなるXの数を更新する
  }
  cout << ans << endl;
  return 0;
}

// 変形するとj - A[j] = i + A[i]となる．これで条件を満たすiというのはi < jかつj - A[j] = i + A[i]を満たすiとなる．この時，cnt[x]:=i + A[i]を満たすiの個数をjを全探索しながら更新していくことでjを評価するときは，cnt配列はi < jのものが作られている状態が作れる．これでcnt[j - A[j]]を答えに足し合わせていくと答えが得られる．
