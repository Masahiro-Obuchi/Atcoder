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
  int N;
  cin >> N;
  vector<int> a(N);
  for (auto &it : a)
    cin >> it;
  int ans = -100000000;
  for (int i = 0; i < N; i++)
  {
    int sumA = 0;
    int idx = -1;
    int sumT = 0;
    for (int j = 0; j < N; j++)
    {
      int tmp = 0;
      if (i == j)
        continue;
      if (i < j)
      {
        for (int k = i; k <= j; k++)
        {
          if ((k - i) % 2 != 0)
            tmp += a[k];
        }
      }
      else
      {
        for (int k = j; k <= i; k++)
        {
          if ((k - j) % 2 != 0)
            tmp += a[k];
        }
      }
      if (tmp > sumA || (idx == -1 && sumA == 0))
      {
        sumA = tmp;
        idx = j;
      }
    }
    if (i < idx)
    {
      for (int k = i; k <= idx; k++)
      {
        if ((k - i) % 2 == 0)
          sumT += a[k];
      }
    }
    else
    {
      for (int k = idx; k <= i; k++)
      {
        if ((k - idx) % 2 == 0)
          sumT += a[k];
      }
    }
    ans = max(ans, sumT);
  }
  cout << ans << endl;
  return 0;
}

//
