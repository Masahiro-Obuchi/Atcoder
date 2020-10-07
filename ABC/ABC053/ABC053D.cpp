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

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  set<int> st;
  for (int i = 0; i < N; i++)
  {
    int A;
    cin >> A;
    st.insert(A);
  }
  int k = st.size();
  if (k % 2 != 0)
    cout << k << endl;
  else
    cout << k - 1 << endl;
  return 0;
}

// 基本的には1枚しかないカードを取り除かれないカードに余っているカードを取り除かれるカードに選ぶことが出来るので操作は「2枚のカードを選んで取り除く」として構わない．
// カードの山にk種類のカードがあったとしてkが奇数なら余っているカードは偶数枚あるので答えはkとなり，偶数ならばどこかで必ず1枚しかないカードを取り除く必要があるので答えはk-1となる．
