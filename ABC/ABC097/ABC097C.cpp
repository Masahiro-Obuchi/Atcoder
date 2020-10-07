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
  string s;
  cin >> s;
  int K;
  cin >> K;
  vector<string> vec;
  for (int i = 0; i < s.size(); i++)
  {
    for (int j = 1; j <= K; j++)
    {
      string tmp = s.substr(i, j);
      vec.push_back(tmp);
    }
  }
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  cout << vec[K - 1] << endl;
  return 0;
}

// 辞書順K番目が長さKを超えることはない
// sortとunique, eraseで重複部分を削除する．
