#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
/*
struct Edge
{
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
*/
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  int sz = 2 * N;
  vector<int> type(sz), com(sz, -1);

  bool ng = false;

  for (int i = 0; i < N; i++)
  {
    cin >> A[i] >> B[i];
    if (A[i] != -1)
    {
      A[i]--;
      if (type[A[i]] != 0)
        ng = true;
      type[A[i]] = i + 1; // id
    }
    if (B[i] != -1)
    {
      B[i]--;
      if (type[B[i]] != 0)
        ng = true;
      type[B[i]] = -(i + 1);
    }

    if (A[i] != -1 && B[i] != -1)
    {
      com[A[i]] = B[i];
      com[B[i]] = A[i];
    }
  }

  if (ng)
  {
    cout << "No" << endl;
    return 0;
  }

  vector<bool> dp(sz + 1);
  dp[0] = true;

  for (int i = 0; i < sz; i++)
  {
    if (!dp[i])
      continue;
    for (int j = i + 1; j < sz; j++)
    {
      int w = j - i + 1;
      if (w % 2 != 0)
        continue;
      int skip = w / 2;
      bool ok = true;
      vector<bool> exist(N);

      for (int k = 0; k < skip; k++)
      {
        int p = i + k, q = i + k + skip;
        if (com[p] != -1 && !(i <= com[p] && com[p] <= j))
          ok = false;
        if (com[q] != -1 && !(i <= com[q] && com[q] <= j))
          ok = false;
        // 両方区間に含まれなければならない

        bool same = false;
        if (type[p] != 0 && type[q] != 0)
        {
          if (type[p] < 0 || type[p] + type[q] != 0)
          {
            ok = false;
          }
          else
            same = true;
        }
        if (type[p] < 0 || type[q] > 0)
          ok = false;
        else
        {
          if (!same && type[p] != 0)
          {
            int v = type[p] - 1;
            if (exist[v])
            {
              ok = false;
            }
            exist[v] = true;
          }
          if (!same && type[q] != 0)
          {
            int v = -type[q] - 1;
            if (exist[v])
            {
              ok = false;
            }
            exist[v] = true;
          }
        }
      }
      if (ok)
        dp[j + 1] = true;
    }
  }

  if (dp[sz])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

// https://atcoder.jp/contests/arc104/editorial/158
