#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

vector<long long> divisor(long long n)
{
  vector<long long> ret;
  for (long long i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      ret.push_back(i);
      if (i * i != n)
        ret.push_back(n / i);
    }
  }
  sort(ret.begin(), ret.end()); // 昇順に並べる
  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (auto &it : A)
    cin >> it;
  sort(A.begin(), A.end());
  set<ll> st;
  if (N == 1)
    cout << 1 << endl;
  else
  {
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
      vector<ll> div = divisor(A[i]);
      bool exist = false;
      for (auto it : div)
      {
        if (st.find(it) != st.end())
          exist = true;
      }
      if (!exist)
        if (i == N - 1 || A[i] != A[i + 1])
          cnt++;
      st.insert(A[i]);
    }
    cout << cnt << endl;
  }
  return 0;
}
