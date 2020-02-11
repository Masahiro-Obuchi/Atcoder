#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> L(N);
  for (int i = 0; i < N; i++)
  {
    cin >> L[i];
  }
  int ans = 0;
  sort(L.begin(), L.end());
  for (int i = 0; i < N; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      for (int k = j + 1; k < N; k++)
      {
        if (L[i] < L[j] + L[k] && L[j] < L[i] + L[k] && L[k] < L[i] + L[j])
          ans++;
      }
    }
  }
  cout << ans << endl;
}

// ギリギリだったから想定解法ではないかも．配列から3つ数字を選んで条件を確かめる問題だから単純に3重ループを回した．計算量を少しでも減らす，かつ，棒の重複を防ぐためにjの条件をi + 1, kの条件をj + 1とした．
// 解説を読んだ感じ蟻本的な解法が求められてたらしい．三角形を構成する棒のうち，1番目に長いものを2番目に長いものを固定する．このとき，3番目に使える棒は「2番目の棒より短く，（3番目だから）一定以上の長さを持つもの．あらかじめソートしておけば二分探索を用いて求めることが出来る
