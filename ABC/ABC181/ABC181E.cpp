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
  int N, M;
  cin >> N >> M;
  vector<ll> H(N), W(M);
  for (auto &it : H)
    cin >> it;
  for (auto &it : W)
    cin >> it;

  sort(H.begin(), H.end());
  sort(W.begin(), W.end());

  map<ll, ll> diff;
  vector<int> idxs;
  for (auto it : W)
  {
    int idx = lower_bound(H.begin(), H.end(), it) - H.begin();
    idxs.push_back(idx);
    if (idx % 2 == 0)
    {
      // idxと組む
      diff[it] = abs(it - H[idx]);
    }
    else
    {
      // idx - 1と組む
      diff[it] = abs(it - H[idx - 1]);
    }
  }

  vector<ll> diff1, diff2;
  for (int i = 1; i < N - 1; i += 2)
  {
    diff1.push_back(abs(H[i] - H[i - 1]));
  }
  for (int i = 2; i < N; i += 2)
  {
    diff2.push_back(abs(H[i] - H[i - 1]));
  }
  vector<ll> sum1((N - 1) / 2 + 1), sum2((N - 1) / 2 + 1);
  for (int i = 0; i < (N - 1) / 2; i++)
  {
    sum1[i + 1] = sum1[i] + diff1[i];
  }
  for (int i = 0; i < (N - 1) / 2; i++)
  {
    sum2[i + 1] = sum2[i] + diff2[i];
  }

  ll ans = INF;
  for (int i = 0; i < M; i++)
  {
    ll tmp = diff[W[i]];
    int idx = idxs[i];
    if (idx % 2 == 0)
    {
      tmp += sum1[idx / 2];
      tmp += sum2[(N - 1) / 2] - sum2[idx / 2];
    }
    else
    {
      tmp += sum2[(N - 1) / 2] - sum2[idx / 2];
      tmp += sum1[(idx - 1) / 2];
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
