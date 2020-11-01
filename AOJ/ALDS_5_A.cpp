#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

// 再帰関数による全探索
bool search(int n, vector<int> &A, int i, int m)
{
  if (m == 0)
    return true;
  else if (i >= n)
    return false;

  return (search(n, A, i + 1, m) || search(n, A, i + 1, m - A[i]));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++)
    cin >> A[i];
  int q;
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    int m;
    cin >> m;
    search(n, A, 0, m) ? cout << "yes" << endl : cout << "no" << endl;
  }
  return 0;
}

// bit全探索だと少し遅いので再帰の方が良さげ
// i番目を使う場合と使わない場合　iの値を1進めてi+1の場合を更新したmで考える．mがちょうど0になった場合にtrueを返し，iがnを超えた場合にfalseを返す
