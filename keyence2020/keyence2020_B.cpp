
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main()
{
  long long N;
  cin >> N;
  vector<pair<long long, long long>> data(N);
  for (int i = 0; i < N; i++)
  {
    long long x, l;
    cin >> x >> l;
    data[i].first = x + l;
    data[i].second = x - l;
  }
  sort(data.begin(), data.end());
  long long int ans = 0, work = -1LL << 60;
  for (int i = 0; i < N; i++)
  {
    if (work <= data[i].second)
    {
      ans++;
      work = data[i].first;
    }
  }
  cout << ans << endl;
}

// 区間スケジューリング問題　端点が重なってもいいことに注意
