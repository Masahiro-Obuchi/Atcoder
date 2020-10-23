#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

ll findSumOfDigits(ll n)
{
  ll sum = 0;
  while (n > 0)
  {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N;
  cin >> N;
  vector<ll> ans;
  for (int i = 0; i <= 1000; i++)
  {
    if (N - i < 0)
      break;
    if (N - i + findSumOfDigits(N - i) == N)
      ans.push_back(N - i);
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (auto it : ans)
    cout << it << endl;
  return 0;
}

// f(x) << xでありf(x)の最大値は9*17 = 153程度であるからNからN-153までを全探索すればよい．(f(x)の範囲が0 <= f(x) <= 153であり．x = N - f(x)であるからxの範囲はN - 153 <= x <= Nである．)
