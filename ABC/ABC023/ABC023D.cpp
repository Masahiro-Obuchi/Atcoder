#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

// 割られた時の風船の高度が全てX以下か判定する
bool check(ll x, int N, vector<pair<ll, ll>> &vec)
{
  vector<double> T(N);
  for (int i = 0; i < N; i++)
  {
    if (x < vec[i].first)
      return false;
    T[i] = (double)(x - vec[i].first) / vec[i].second;
  }
  sort(T.begin(), T.end());
  for (int i = 0; i < N; i++)
    if (T[i] < i)
      return false;
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<pair<ll, ll>> HS(N);
  for (int i = 0; i < N; i++)
  {
    cin >> HS[i].first >> HS[i].second;
  }
  ll left = 0, right = INF; //左　満たさない側　右　満たす側
  while (left + 1 < right)
  {
    ll mid = (left + right) / 2;
    if (check(mid, N, HS))
      right = mid;
    else
      left = mid;
  }
  cout << right << endl;
  return 0;
}

// 最小化問題として考えることは難しく，最小化問題の代わりにある高さxを保ちながら風船を割ることが出来るかという判定問題に変形することで効率的に解くことが出来る．超えてはならないxが決まっているものとする．このとき，風船は(X - Hi) / Si秒以内に割らなければいけない．(もしもX < HiならこのXでは負かであることが分かる) ある値Optを基準としてOpt > Xならばどうやっても達成できない．Opt < xならば貪欲法アルゴリズムで達成できる．このOptの値が求める答え．
// このOptを求める際に二分探索を用いることが出来る．Xを定めた時に制限時間でソートして判定する．
// 得点の最小値Xを求める
// 割られた時の風船の高度は全てX以下．このXの最小値が答え．風船iは(X - Hi) / Si秒以内に割ることが出来る．このxの最小値が答え．
// おそらく二分探索を実装しないと解けない問題
// 風船iをTi秒以内に割ることが出来るかを見る(iがTiよりおおきくなってしまったらアウト)
