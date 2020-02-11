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
  sort(L.begin(), L.end());
  int ans = 0;
  for (int mid = N - 1; mid >= 0; mid--)
  {
    for (int low = mid - 1; low >= 0; low--)
    {
      auto itr = lower_bound(L.begin(), L.end(), L[mid] + L[low]); // lower_bound, upper_boundの使い方
      int ng = distance(itr, L.end());
      ans += (N - 1 - mid) - ng; // N - 1個からmidを引き，midより小さいものを排除，また二分探索で得られたitrを使ってdistanceで得られたngを引くことによってlow + midより大きいものを排除
    }
  }
  cout << ans << endl;
  return 0;
}

// けんちょんさんのブログを参考に　http://drken1215.hatenablog.com/entry/2019/10/20/032700
