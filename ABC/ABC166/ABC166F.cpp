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
  vector<int> d(3);
  for (int i = 0; i < 3; i++)
    cin >> d[i];

  vector<P> q;
  for (int i = 0; i < N; i++)
  {
    string S;
    cin >> S;
    int a = 0, b = 0;
    if (S == "AB")
      a = 0, b = 1;
    if (S == "AC")
      a = 0, b = 2;
    if (S == "BC")
      a = 1, b = 2;
    q.emplace_back(a, b);
  }
  string ans;
  auto add = [&](int a, int b) {
    d[a]++;
    d[b]--;
    ans += 'A' + a;
  }; // aにbを足す
  q.emplace_back(0, 1);
  for (int i = 0; i < N; i++)
  {
    int a = q[i].first;
    int b = q[i].second;
    if (!d[a] && !d[b])
    {
      cout << "No" << endl;
      return 0;
    }
    if (!d[a])
    {
      add(a, b);
    }
    else if (!d[b])
    {
      add(b, a);
    }
    else
    {
      int na = q[i + 1].first;
      int nb = q[i + 1].second;
      if (a == na || a == nb)
      {
        add(a, b);
      }
      else
      {
        add(b, a);
      }
    }
  }
  cout << "Yes" << endl;
  for (int i = 0; i < N; i++)
  {
    cout << ans[i] << endl;
  }
  return 0;
}

// A + B + C >= 2のとき A + B + C = 2かつ足し引きする数が共に1かつ最後のターンではないとき，次のターンを見て今のターンと文字列が異なれば次のターンで使われる方に足す．1 1 0や1 0 1のときだけ気を付けなければならない．
