#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<pair<int, int>> red(N);
  for (int i = 0; i < N; i++)
  {
    int a, b;
    cin >> a >> b;
    red[i].first = a;
    red[i].second = b;
  }
  vector<pair<int, int>> blue(N);
  for (int i = 0; i < N; i++)
  {
    int c, d;
    cin >> c >> d;
    blue[i].first = c;
    blue[i].second = d;
  }
  sort(red.begin(), red.end(), greater<pair<int, int>>());
  int ans = 0;
  vector<bool> used(N, false);
  int match = -1;
  int min = 1000000000;
  for (int i = 0; i < N; i++)
  {
    match = -1;
    min = 1000000000;
    for (int j = 0; j < N; j++)
    {
      if (!used[j] && blue[j].first > red[i].first && blue[j].second > red[i].second)
      {
        int tmp = blue[j].second;
        if (tmp < min)
        {
          min = tmp;
          match = j;
        }
      }
    }
    if (match >= 0)
    {
      used[match] = true;
    }
  }
  for (int i = 0; i < N; i++)
  {
    if (used[i])
      ans++;
  }
  cout << ans << endl;
}

// マッチした青い点をvector<bool>として保持する．赤い点を一つ決めた時に既にマッチしていない青い点を順に見ていき，青い点のx座標 - 赤い点のx座標 + 青い点のy座標 - 赤い点のy座標が最も小さい点と現在見ている赤い点をマッチさせる．tmpがsumより小さくなったときにマッチする青い点の番号とsumを更新し，最後にその番号のboolをtrueにする．外側のループの初めにsumとマッチする番号の初期化を忘れないように．また，matchが0より大きいときに限り，usedをtrueにするようにする．
// redをソートすることで厳しい方から先にマッチングさせていく？
// 上は間違い
// redをgreaterでsortするからredのx座標によってソートされている．すなわち赤い点のxの大きいものから見ていき，赤い点よりx座標もy座標も大きいものの中から最もy座標が小さいものから選んでいくのが最適となる．値が近いもの同士で結んでいくといいということ．二部グラフの最大マッチング，最大流アルゴリズムで解けるらしい．
