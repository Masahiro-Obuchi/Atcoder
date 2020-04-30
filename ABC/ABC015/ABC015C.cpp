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

int N, K;

bool dfs(vector<vector<int>> &data, int numQ, int value)
{ // 今の質問数，値からどこにいるかを格納
  if (numQ == N)
    return (value == 0); // 質問がもうなければ0になっているかを調べる
  for (int i = 0; i < K; i++)
  {
    if (dfs(data, numQ + 1, value ^ data[numQ][i]))
      return true;
  }
  return false; // 探索した結果，0になる組み合わせが無ければfalse
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> K;
  vector<vector<int>> data(N, vector<int>(K));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < K; j++)
    {
      cin >> data[i][j];
    }
  }
  if (dfs(data, 0, 0))
    cout << "Found" << endl;
  else
    cout << "Nothing" << endl;
  return 0;
}

// 全探索 こういった全探索はdfsを使うべき...
// 木構造じゃないdfs
