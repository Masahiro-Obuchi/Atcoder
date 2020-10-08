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
    ll weight;
    Edge(int t, ll w) : to(t), weight(w) {}
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
  bool can = false;
  int k;
  for (int i = 1; i <= 1000; i++)
  {
    if (i * (i - 1) % 2 == 0 && i * (i - 1) / 2 == N)
    {
      k = i;
      can = true;
      break;
    }
  }

  if (can)
  {
    cout << "Yes" << endl;
    for (int i = 1; i <= 1000; i++)
    {
      if (i * (i - 1) % 2 == 0 && i * (i - 1) / 2 == N)
      {
        k = i;
        break;
      }
    }

    cout << k << endl;
    vector<vector<int>> ans(k);
    int now = 1;
    for (int i = 0; i < k; i++)
    {
      int idx = i + 1;
      while (ans[i].size() < k - 1)
      {
        ans[i].push_back(now);
        ans[idx].push_back(now);
        now++;
        idx++;
      }
    }
    for (int i = 0; i < k; i++)
    {
      cout << ans[i].size() << " ";
      for (int j = 0; j < ans[i].size(); j++)
      {
        cout << ans[i][j] << " ";
      }
      cout << endl;
    }
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}

// ちょうど2回しか使われず，各集合1つしか共通の値がないことから要素k-1個の集合がk個あると分かる．集合のそれぞれの値から他の集合へ辺が伸びているイメージ
