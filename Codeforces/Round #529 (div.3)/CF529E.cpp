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

void solve()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += (s[i] == '(' ? 1 : -1);

  if (sum == -2)
  {
  }
  else if (sum == 2)
  {
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++)
      s[i] = (s[i] == '(' ? ')' : '(');
  }
  else
  {
    cout << 0 << endl;
    return;
  }

  int sm = 0, mn = 0, ans = 0;
  for (int i = 0; i < n; i++)
  {
    sm += (s[i] == '(' ? 1 : -1);
    if (s[i] == ')')
      if (mn >= 0)
        ans++;

    mn = min(mn, sm);
    if (mn < -2)
    {
      cout << 0 << endl;
      return;
    }
  }
  cout << ans << endl;
  return;
}
// ( を+1、) を-1として、s の累積和を求める。正しい括弧列の条件は任意の区切り位置で、累積和が0以上である。 全ての文字の合計がちょうど0になる。 の2つを満たすこと.まず合計だけを考えます。1文字の変更後に合計が0になることが必要条件なので、合計が2の場合、( を ) に変えることで正しい括弧列になる可能性がある。合計が-2の場合、) を ( に変えることで正しい括弧列になる可能性がある。そうでない場合、1文字変更後に正しい括弧列になることはない。と場合分けできます。ここでもし合計が2の場合は s 全体を鏡写しに（実装においては、文字列全体を反転させ、( と ) を反転）することで合計が-2の場合と同一視できるので、こちらだけを考えます。

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  t = 1;
  for (int i = 0; i < t; i++)
  {
    solve();
  }
  return 0;
}
