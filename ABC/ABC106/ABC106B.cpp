#include <bits/stdc++.h>
using namespace std;

int num_div(int n)
{
  int ans = 1;
  vector<int> x(n + 1);
  int num = n; // 素因数分解する変数num
  for (int i = 2; i <= n; i++)
  {
    while (num % i == 0)
    {            // 素数で割り切れなくなるまで割っていく
      x.at(i)++; // 割った個数を配列に足す
      num /= i;
    }
  }
  for (int i = 2; i <= n; i++)
  {
    ans *= x.at(i) + 1; // それぞれを+1して掛けていく
  }
  return ans;
}

int main()
{
  int N;
  cin >> N;
  int cnt = 0;
  for (int i = 1; i <= N; i++)
  {
    if (i % 2 != 0 and num_div(i) == 8)
      cnt++;
  }
  cout << cnt << endl;
}
