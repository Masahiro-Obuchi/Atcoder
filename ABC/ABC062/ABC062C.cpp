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

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll H, W;
  cin >> H >> W;
  if (H % 3 == 0 || W % 3 == 0)
    cout << 0 << endl;
  else
  {
    ll ans = INF;
    for (int i = 1; i <= H - 1; i++)
    {
      ll Smax = 0, Smin = INF, Smax2 = 0, Smin2 = INF;
      ll S1 = 0, S2 = 0, S3 = 0, S4 = 0, S5 = 0;
      S1 = i * W;
      S2 = (H - i) * (W / 2);
      S3 = (H - i) * ((W + 1) / 2);
      S4 = ((H - i) / 2) * W;
      S5 = ((H - i + 1) / 2) * W;
      Smax = max(S1, max(S2, S3));
      Smin = min(S1, min(S2, S3));
      Smax2 = max(S1, max(S4, S5));
      Smin2 = min(S1, min(S4, S5));
      ans = min(ans, min(Smax - Smin, Smax2 - Smin2));
    }
    for (int j = 1; j <= W - 1; j++)
    {
      ll Smax = 0, Smin = INF, Smax2 = 0, Smin2 = INF;
      ll S1 = 0, S2 = 0, S3 = 0, S4 = 0, S5 = 0;
      S1 = H * j;
      S2 = (W - j) * (H / 2);
      S3 = (W - j) * ((H + 1) / 2);
      S4 = ((W - j) / 2) * H;
      S5 = ((W - j + 1) / 2) * H;
      Smax = max(S1, max(S2, S3));
      Smin = min(S1, min(S2, S3));
      Smax2 = max(S1, max(S4, S5));
      Smin2 = min(S1, min(S4, S5));
      ans = min(ans, min(Smax - Smin, Smax2 - Smin2));
    }
    cout << ans << endl;
  }
  return 0;
}

// 分割面を決め打ち　縦で分割と横で分割をする．　分割した後に更に縦に分割するか横に分割するかの2通りがあるから両方計算する．両パターンでSmaxとSminを計算してansをSmax - Sminの小さい方との最小で更新する．　各分割面に対してSmaxとSminを求める．
