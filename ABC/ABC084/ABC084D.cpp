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

bool isPrime(int num)
{
  if (num < 2)
    return false;
  else if (num == 2)
    return true;
  else if (num % 2 == 0)
    return false;

  double sqrtNum = sqrt(num);

  for (int i = 3; i <= (int)sqrtNum; i++)
  {
    if (num % i == 0)
      return false;
  }

  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int Q;
  cin >> Q;
  vector<int> l(Q), r(Q);
  for (int i = 0; i < Q; i++)
    cin >> l[i] >> r[i];
  vector<int> cnt(100010);
  for (int i = 3; i <= 100000; i++)
  {
    cnt[i] = cnt[i - 1];
    if (i % 2 != 0 && isPrime(i) && isPrime((i + 1) / 2))
      cnt[i]++;
  }
  for (int i = 0; i < Q; i++)
  {
    int ans = cnt[r[i]] - cnt[l[i] - 1];
    cout << ans << endl;
  }
  return 0;
}

// 累積和的な解き方？まず累積和の配列を作って3から10^5まで2017に似た数かを調べて数を累積していく
//　その後，cnt[r] - cnt[l - 1]をすることによって求めることが出来る
