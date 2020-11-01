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
  int N;
  cin >> N;
  vector<ll> A(3 * N);
  for (auto &it : A)
    cin >> it;

  vector<pair<ll, ll>> score(N + 1);
  ll sum_front = 0;
  priority_queue<ll, vector<ll>, greater<ll>> que_front;
  for (int i = 0; i < N; i++)
  {
    sum_front += A[i];
    que_front.push(A[i]);
  }
  score[0].first = sum_front;

  for (int k = N; k < 2 * N; k++)
  {
    sum_front += A[k];
    que_front.push(A[k]);
    sum_front -= que_front.top();
    que_front.pop();
    score[k - (N - 1)].first = sum_front;
  }

  ll sum_back = 0;
  priority_queue<ll> que_back;
  for (int i = 2 * N; i < 3 * N; i++)
  {
    sum_back += A[i];
    que_back.push(A[i]);
  }
  score[N].second = sum_back;

  for (int k = 2 * N - 1; k >= N; k--)
  {
    sum_back += A[k];
    que_back.push(A[k]);
    sum_back -= que_back.top();
    que_back.pop();
    score[k - N].second = sum_back;
  }

  ll ans = -INF;
  for (int i = 0; i < N + 1; i++)
  {
    ans = max(ans, score[i].first - score[i].second);
  }
  // cerr << score[1].first << " " << score[1].second << endl;
  cout << ans << endl;
  return 0;
}

// aの前半k要素は黒色または赤色のみで，aの後半3N - k要素は黒色または青色のみである．この条件が成り立つような整数kをN<=k<=2Nの範囲で全探索する．各kについて答えを求められればそれらの最大値が全体の答えとなる．kを一つ固定する．あらかじめ，aの前半N要素をpushしておく．また現在キューに入っている要素の総和を保持しておく．要素akをpushしたあと，最小をpopすればよい．総和も足し引きする．青も同様．2*N - N + 1 = N + 1
