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

void eulerPhi(vector<ll> &euler)
{
  for (int i = 0; i < euler.size(); i++)
    euler[i] = i;
  for (int i = 2; i < euler.size(); i++)
  {
    if (euler[i] == i)
    {
      for (int j = i; j < euler.size(); j += i)
      {
        euler[j] = euler[j] / i * (i - 1);
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  vector<ll> euler(1000010);
  vector<ll> answer(1000010);
  eulerPhi(euler);
  answer[1] = 2;
  for (int i = 2; i < euler.size(); i++)
  {
    answer[i] = answer[i - 1] + euler[i];
  }
  for (int i = 0; i < t; i++)
  {
    int n;
    cin >> n;
    cout << answer[n] << endl;
  }
  return 0;
}
// n群目のファレイ数列の要素数を数える問題．n-1群目までのファレイ数列が分かっていると仮定したときn番目のファレイ数列の要素数は(n - 1群目の要素数 + nと互いに素なn未満の自然数の数)となる． dp[i]:=i番目のファレイ数列の要素数　dp[0]:=1, dp[1]:=2とすると，更新式はdp[i + 1] = dp[i] + phi[i + 1]とかける．phi[i]はi未満の自然数であってiと互いに素な自然数の数を表す．phi[i]を事前に求めておく必要があるがこれはオイラーの\phi関数を使って求めることが出来る．しかし，オイラーの\phi関数を用いるためにはそれぞれの数を素因数分解する必要があるが，愚直に行うと間に合わない．そこでエラトステネスの篩とのアナロジーを用いて次のような手続きを考える
// 1. phi[i] = iとして求めたいN番目の数まで初期化しておく．2. i=2～Nまで以下を回す　phi[i]==iのときiの倍数の添え字を持つもの（自身を含む）を(i-1)/i倍する．その他の時何もしない．この操作を行うことで配列phiに\phi関数を実現できる．素数を発見してその素因数を持ちうるものに対して先んじて(i-1)/iを掛けることを繰り返すと最終的に全ての要素が\phi関数と同じ計算をすることになる．
