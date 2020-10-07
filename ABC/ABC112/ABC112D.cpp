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
  ll N, M;
  cin >> N >> M;
  vector<ll> c = divisor(M);
  ll ans = 0;
  for (auto it : c)
  {
    if ((M / it) >= N)
      ans = max(ans, it);
  }
  cout << ans << endl;
  return 0;
}

// 約数列挙をしてそれらの値でMを割っていく．Mを割った値がN以上になったらansを更新していく．このようにして最大になったものが答え．
