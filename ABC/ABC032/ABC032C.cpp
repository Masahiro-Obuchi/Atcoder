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
  bool zero = false;
  bool smaller = false;
  for (auto &it : s)
  {
    cin >> it;
    if (it == 0)
      zero = true;
    if (it <= K)
      smaller = true;
  }
  if (zero)
    cout << N << endl;
  else if (!smaller)
    cout << 0 << endl;
  else
  {
    int ans = 0;
    ll sum = 1;
    int r = 0;
    for (int l = 0; l < N; l++)
    {
      r = l;
      while (sum <= K)
      {
        cerr << "l: " << l << "   r: " << r << "   sum: " << sum << "   ans: " << ans << endl;
        if (r == N)
          break;
        else
        {
          sum *= s[r];
          r++;
          if (sum <= K)
          {
            ans = max(ans, r - l + 1);
          }
          else
            break;
        }
      }
      sum /= s[l];
    }

    cout << ans << endl;
  }
  return 0;
}
// 尺取りが良さそう　Kを超えない限りrを右に進める．　Kを超えたらlを左に進める　max(r - l, ans)で更新
