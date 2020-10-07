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

ll oddSolve(ll a)
{
  return (((a + 1) / 2) % 2 == 0) ? 0 : 1;
}

ll sumXOR(ll a)
{
  if (a % 2 == 1)
    return oddSolve(a);
  else
    return oddSolve(a + 1) ^ (a + 1);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll A, B;
  cin >> A >> B;
  cout << (sumXOR(B) ^ sumXOR(A - 1)) << endl;
  return 0;
}

// XORの世界では足し算も引き算も同じ　排他的論理和の計算順序は入れ替えてよくまた，どの非負整数nについてもn ^ n = 0であるからA > 0 のときF(A, B) = F(0, A - 1) + F(0, B)が成り立つ．そこでf(n) = F(0, n)を求めることを考える．　またxorは任意の偶数についてn ^ (n + 1) = 1という性質がある．この性質を用いれば0 ^ 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 = (0 ^ 1) ^ (2 ^ 3) ^ (4 ^ 5) ^ 6 = 1 ^ 1 ^ 1 ^ 6　のように計算できる．1 ^ 1 ^ 1 ^ ... ^ 1は1が偶数なら0，奇数個なら1となる．
// 実験をする　Xが奇数なら，(X + 1)/2が偶数なら0，奇数なら1, Xが偶数ならX + 1が奇数なのでその答えからX + 1を引く(xorの世界で足す)
