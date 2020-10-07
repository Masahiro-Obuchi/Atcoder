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
//using Graph = vector<vector<Edge>>;
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;
const double PI = acos(-1.0);

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

bool isPrime(long long num)
{
  if (num < 2)
    return false;
  else if (num == 2)
    return true;
  else if (num % 2 == 0)
    return false;

  double sqrtNum = sqrt(num);

  for (int i = 3; i <= (int)sqrtNum; i++)
  {
    if (num % i == 0)
      return false;
  }

  return true;
}

vector<int> Eratosthenes(const int N)
{
  vector<bool> is_prime(N + 1);
  for (int i = 0; i <= N; i++)
  {
    is_prime[i] = true;
  }
  vector<int> P;
  for (int i = 2; i <= N; i++)
  {
    if (is_prime[i])
    {
      for (int j = 2 * i; j <= N; j += i)
      {
        is_prime[j] = false;
      }
      P.emplace_back(i);
    }
  }
  return P;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> prime = Eratosthenes(55555);
  vector<int> ans;
  int cnt = 0;
  int idx = 1;
  while (cnt < N)
  {
    if (prime[idx] % 5 == 1)
    {
      ans.push_back(prime[idx]);
      cnt++;
    }
    idx++;
  }
  for (auto &it : ans)
    cout << it << " ";
  cout << endl;
}

// 5個選んで，足し上げることから，配列内の全ての数が5で割って1余る数であれば5個足し上げれば必ず5の倍数になる．(mod5の世界で考える．上記のように考えると余った1を引けば残りの数は全て5の倍数である．そして余った1を5個足し上げると5になるため選んだ5個の数の和は必ず5の倍数になる．)
