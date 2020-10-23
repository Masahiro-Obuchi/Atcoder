#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int m;
  cin >> m;
  vector<pair<ll, ll>> stars(m);
  for (int i = 0; i < m; i++)
    cin >> stars[i].first >> stars[i].second;
  int n;
  cin >> n;
  vector<pair<ll, ll>> pic(n);
  for (int i = 0; i < n; i++)
    cin >> pic[i].first >> pic[i].second;
  pair<int, int> ans;
  ans.first = -1, ans.second = -1;
  for (int i = 0; i < n; i++)
  {
    pair<int, int> tmp;
    tmp.first = pic[i].first - stars[0].first, tmp.second = pic[i].second - stars[0].second;
    bool allCollect = true;
    for (int j = 0; j < m; j++)
    {
      bool isExist = false;
      pair<int, int> candidate;
      candidate.first = stars[j].first + tmp.first, candidate.second = stars[j].second + tmp.second;
      for (int k = 0; k < n; k++)
      {
        if (candidate.first == pic[k].first && candidate.second == pic[k].second)
          isExist = true;
      }
      if (!isExist)
        allCollect = false;
    }
    if (allCollect)
    {
      ans.first = tmp.first, ans.second = tmp.second;
      break;
    }
  }
  cout << ans.first << " " << ans.second << endl;
}

// 探したい星座の初めの点と写真の中の各点の差分を解候補とする．それを探したい星座の全ての点に対して適用し，それが全て写真上に存在すればok．
