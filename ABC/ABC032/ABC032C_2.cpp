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
  ll N, K;
  cin >> N >> K;
  vector<ll> s(N);
  for (auto &it : s)
    cin >> it;
  for (int i = 0; i < N; i++)
  {
    if (s[i] == 0)
    {
      cout << N << endl;
      return 0;
    }
  }
  int res = 0;
  int right = 0;
  ll mul = 1;
  for (int left = 0; left < N; left++)
  {
    while (right < N && mul * s[right] <= K)
    {
      mul *= s[right];
      right++;
    }
    res = max(res, right - left);
    if (left == right)
      right++;
    else
      mul /= s[left];
  }
  cout << res << endl;
  return 0;
}
// 尺取りが良さそう　Kを超えない限りrを右に進める．　Kを超えたらlを左に進める　max(r - l, ans)で更新
