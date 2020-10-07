#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int lcm(int a, int b)
{
  int g = gcd(a, b);
  return a / g * b;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> C(N), S(N), F(N);
  for (int i = 0; i < N - 1; i++)
    cin >> C[i] >> S[i] >> F[i];

  vector<int> ans;

  for (int i = 0; i < N - 1; i++)
  {
    if (i != 0)
    {
      for (auto &a : ans)
      {
        a = max(S[i], ((a + (F[i] - 1)) / F[i]) * F[i]) + C[i];
      }
    }
    ans.push_back(C[i] + S[i]);
  }
  cerr << lcm(25, 17) << endl;
  for (int i = 0; i < N - 1; i++)
    cout << ans[i] << endl;
  cout << 0 << endl;
  return 0;
}

// for (auto &a : ans) S[i]と要素をF[i]で割ったものの切り上げ * F[i] のmaxを取ってC[i]を足したもので要素を更新して最後にansにC[i] + S[i]を加えるということを0からN - 1まで繰り返す．
// max(S[i], t + F[j] - t % F[j])とするのが楽
