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
  ll N;
  cin >> N;
  string ans;
  if (N == 0)
    ans += "0";
  else
  {
    while (N != 0) // Nは負の数もあり得るから条件はN != 0のとき
    {
      int rem = N % (-2);
      if (rem == -1)
        rem += 2;
      ans += (char)(rem + '0');
      cerr << ans << endl;
      N -= rem;
      N /= -2; // Nから余りを取り除いて-2で割る．
    }
    reverse(ans.begin(), ans.end());
  }
  cout << ans << endl;
  return 0;
}

// -2で割るとはどういったことか　-2で割るとはN = (-2)q + rになるようにrを調整すること　これを繰り返して余りを追加していく　なおC++では負の数を割る時に余りが-になる すなわち0か-1となるため-1のときに+2を足す
