#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

// Graph
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
// using Graph = vector<vector<int>>;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  map<int, int> A;
  ll sum = 0;
  for (int i = 0; i < N; i++)
  {
    int a;
    cin >> a;
    sum += a;
    A[a]++;
  }
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++)
  {
    int B, C;
    cin >> B >> C;
    ll tmp = A[B];
    sum -= B * tmp;
    sum += C * tmp;
    A[B] -= tmp;
    A[C] += tmp;
    cout << sum << endl;
  }
  return 0;
}
