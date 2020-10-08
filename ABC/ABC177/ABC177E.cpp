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

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

const int MAX = 15001000;
bool IsPrime[MAX];
int MinFactor[MAX];
vector<int> preprocess(int n = MAX)
{
  vector<int> res;
  for (int i = 0; i < n; ++i)
    IsPrime[i] = true, MinFactor[i] = -1;
  IsPrime[0] = false;
  IsPrime[1] = false;
  MinFactor[0] = 0;
  MinFactor[1] = 1;
  for (int i = 2; i < n; ++i)
  {
    if (IsPrime[i])
    {
      MinFactor[i] = i;
      res.push_back(i);
      for (int j = i * 2; j < n; j += i)
      {
        IsPrime[j] = false;
        if (MinFactor[j] == -1)
          MinFactor[j] = i;
      }
    }
  }
  return res;
}

vector<int> primes(1000010);

bool prime_factor(int n)
{
  while (n != 1)
  {
    int prime = MinFactor[n];
    int exp = 0;
    while (MinFactor[n] == prime)
    {
      ++exp;
      n /= prime;
    }
    if (primes[prime] == 0)
      primes[prime]++;
    else
      return false;
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &it : A)
    cin >> it;

  preprocess();
  bool pairwise_coprime = true;
  for (int i = 0; i < N; i++)
  {
    if (!prime_factor(A[i]))
      pairwise_coprime = false;
  }
  if (pairwise_coprime)
  {
    cout << "pairwise coprime" << endl;
    return 0;
  }
  else
  {
    int gcdAll = gcd(A[0], A[1]);
    for (int i = 1; i < N; i++)
    {
      gcdAll = gcd(gcdAll, A[i]);
    }
    if (gcdAll == 1)
      cout << "setwise coprime" << endl;
    else
      cout << "not coprime" << endl;
  }
  return 0;
}
