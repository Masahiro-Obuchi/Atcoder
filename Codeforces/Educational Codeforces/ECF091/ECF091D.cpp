#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
// using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  ll x, k, y;
  cin >> x >> k >> y;
  vector<ll> a(n);
  for (auto &it : a)
    cin >> it;
  vector<ll> b(m);
  for (auto &it : b)
    cin >> it;
  int bIdx = 0;
  vector<int> btoa;
  for (int i = 0; i < n; i++)
  {
    if (bIdx < m && a[i] == b[bIdx])
    {
      bIdx++;
      btoa.push_back(i);
    }
  }
  if (bIdx != m)
  {
    cout << -1 << endl;
    return 0;
  }
  else
  {
    int left = b[0], right = 0;
    int cnt = 0;
    ll maxValue = 0;
    ll ans = 0;
    for (int i = 0; i < btoa[0]; i++)
    {
      cnt++;
      maxValue = max(maxValue, a[i]);
    }
    if (cnt < k)
    {
      if (maxValue > left)
      {
        cout << -1 << endl;
        return 0;
      }
      else
      {
        ans += cnt * y;
      }
    }
    else
    {
      int need = cnt % k;
      ans += need * y;
      cnt -= need; // cntをkで割った余りは全てBerserkで消す必要あり

      if (y * k >= x)
      {
        ans += cnt / k * x; // y * k >= xのときは全てFireballで消す
      }
      else if (maxValue < left)
      {
        ans += cnt * y; // そうでないかつmaxValueがleftより小さい場合はBerserkで消す
      }
      else
      {
        ans += (cnt - k) * y + x; // maxValueがleftより大きい場合はkだけ残してBerserkで消し，残りをFireballを一回使って消す
      }
    }

    for (int i = 1; i < m; i++)
    {
      right = b[i], left = b[i - 1];
      cnt = 0;
      maxValue = 0;
      for (int j = btoa[i - 1] + 1; j < btoa[i]; j++)
      {
        cnt++;
        maxValue = max(maxValue, a[j]);
      }
      if (cnt < k)
      {
        if (maxValue > max(left, right))
        {
          cout << -1 << endl;
          return 0;
        }
        else
        {
          ans += cnt * y;
        }
      }
      else
      {
        int need = cnt % k;
        ans += need * y;
        cnt -= need;

        if (y * k >= x)
        {
          ans += cnt / k * x;
        }
        else if (maxValue < max(left, right))
        {
          ans += cnt * y;
        }
        else
        {
          ans += (cnt - k) * y + x;
        }
      }
    }

    cnt = 0;
    maxValue = 0;
    right = b[m - 1];
    for (int i = btoa[m - 1] + 1; i < n; i++)
    {
      cnt++;
      maxValue = max(maxValue, a[i]);
    }
    if (cnt < k)
    {
      if (maxValue > right)
      {
        cout << -1 << endl;
        return 0;
      }
      else
      {
        ans += cnt * y;
      }
    }
    else
    {
      int need = cnt % k;
      ans += need * y;
      cnt -= need;

      if (y * k >= x)
      {
        ans += cnt / k * x;
      }
      else if (maxValue < right)
      {
        ans += cnt * y;
      }
      else
      {
        ans += (cnt - k) * y + x;
      }
    }

    cout << ans << endl;
  }
  return 0;
}

// k以上あれば区間の最大が左右より大きくても消すことが可能
