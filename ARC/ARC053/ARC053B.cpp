#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define PI 3.14159265358979
using namespace std;
using ll = long long;
using P = pair<int, int>;
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
// using Graph = vector<vector<Edge>>;
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string S;
  cin >> S;
  vector<int> cnt(26, 0);
  for (int i = 0; i < S.size(); i++)
  {
    cnt[S[i] - 'a']++;
  }
  int odd = 0;
  for (int i = 0; i < 26; i++)
    if (cnt[i] % 2 != 0)
    {
      odd++;
      cnt[i]--;
    }
  int even = 0;
  for (int i = 0; i < 26; i++)
    even += cnt[i];
  int ans = 0;
  if (odd == 0)
    ans = even;
  else
    ans = (even / 2) / odd * 2 + 1;
  cout << ans << endl;
  return 0;
}

// まず各アルファベットの数を数える．
// その後偶数の数を数える(奇数だったものは-1をする)
// (偶数の数 / 2) / (奇数の数) * 2 + 1が答え
