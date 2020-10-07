#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> R(N);
  for (int i = 0; i < N; i++)
  {
    cin >> R[i];
  }
  double ans = 0;
  sort(R.begin(), R.end(), greater<int>());
  for (int i = 0; i < N; i++)
  {
    if (i % 2 == 0)
      ans += 3.141592 * pow(R[i], 2);
    else
      ans -= 3.141592 * pow(R[i], 2);
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<double> R(N);
  for (int i = 0; i < N; i++)
  {
    cin >> R[i];
  }
  double ans = 0;
  sort(R.begin(), R.end(), greater<int>());
  for (int i = 0; i < N; i++)
  {
    if (i % 2 == 0)
      ans += 3.1415928979 * pow(R[i], 2);
    else
      ans -= 3.1415928979 * pow(R[i], 2);
  }
  cout << setprecision(14) << ans << endl;
}

// 出力フォーマットを明記
