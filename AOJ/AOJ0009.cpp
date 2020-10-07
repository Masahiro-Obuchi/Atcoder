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
  int n;
  while (scanf("%d", &n) != EOF)
  {
    vector<int> ans = Eratosthenes(n);
    cout << ans.size() << endl;
  }
  return 0;
}
