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
  string S;
  cin >> S;
  int ans = 0;
  for (int i = 0; i < N; i++)
  {
    map<char, int> mp;
    mp[S[i]]++;
    int AT = 0, CG = 0;
    for (int j = i + 1; j < N; j++)
    {
      mp[S[j]]++;
      if (mp['A'] == mp['T'] && mp['C'] == mp['G'])
      {
        ans++;
        AT = mp['A'];
        CG = mp['C'];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
