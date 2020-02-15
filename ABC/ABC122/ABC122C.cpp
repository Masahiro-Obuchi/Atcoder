#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<int> sum(N);
  sum[0] = 0;
  vector<bool> ac(N);
  for (int i = 1; i < N; i++)
  {
    if (S[i - 1] == 'A' and S[i] == 'C')
    {
      sum[i] = sum[i - 1] + 1;
      ac[i] = true;
    }
    else
      sum[i] = sum[i - 1];
  }
  vector<int> a;
  for (int i = 0; i < Q; i++)
  {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int ans = 0;
    if (l == 0)
    {
      ans = sum[r] - sum[0];
    }
    else
    {
      ans = sum[r] - sum[l - 1];
      if (ac[l])
        ans--;
    }
    a.push_back(ans);
  }
  for (int i = 0; i < Q; i++)
  {
    cout << a[i] << endl;
  }
}

// 累積和　i文字目までに何回出現するかを数える．lが0になるときと，S[l]が"AC"の'C'になる時に注意 右隣がCであるようなAを数えるのが単純．このようなAをaとするとli文字目からri-1文字目までのaを数えよとなる．ri文字目がaであってもその右端のCが区間からはみ出てしまうため．このようにしてaの累積和を求めると答えはsumri-1 - sumli-1となる．
