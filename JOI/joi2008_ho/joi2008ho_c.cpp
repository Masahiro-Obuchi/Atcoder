#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  ll M;
  cin >> M;
  vector<ll> P(N);
  for (int i = 0; i < N; i++)
    cin >> P[i];
  P.push_back(0);
  vector<ll> doubleResults;
  for (int i = 0; i < N + 1; i++)
  {
    for (int j = 0; j < N + 1; j++)
    {
      doubleResults.push_back(P[i] + P[j]);
    }
  }

  sort(doubleResults.begin(), doubleResults.end());

  ll ans = 0;
  for (int i = 0; i < doubleResults.size(); i++)
  {
    ll tmp = doubleResults[i];
    if (tmp > M)
      break;
    int index = upper_bound(doubleResults.begin(), doubleResults.end(), M - tmp) - doubleResults.begin();
    if (index == 0)
      break;
    else
      ans = max(ans, tmp + doubleResults[index - 1]);
  }
  cout << ans << endl;
  return 0;
}

// 投げない->0点の的に当たる．4本の矢を投げることをまず2本の矢を投げて次に2本の矢を投げることを考える．矢を2本投げて得られる結果(N + 1)^2を列挙しておく．更にソート．最初の2本の矢の合計点をがQiであったと仮定する．残りの2本の矢の最適な得点を求めるためにはQi + Qj <= Mを満たすjのうち，Qjが最も大きくなるものを選べばよい．これは二分探索で求めることが出来る．各iに対して最適なjを求めればよいからO(N^2logN)
