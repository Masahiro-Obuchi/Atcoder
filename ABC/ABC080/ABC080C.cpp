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
  vector<vector<int>> F(N, vector<int>(10));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      cin >> F[i][j];
    }
  }
  vector<vector<ll>> P(N, vector<ll>(11));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 11; j++)
    {
      cin >> P[i][j];
    }
  }
  ll ans = -INF;
  for (int bit = 1; bit < (1 << 10); bit++)
  {
    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
      int cnt = 0;
      for (int j = 0; j < 10; j++)
      {
        if ((bit & (1 << j)) && (F[i][j] == 1))
          cnt++;
      }
      sum += P[i][cnt];
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}

// bit全探索
