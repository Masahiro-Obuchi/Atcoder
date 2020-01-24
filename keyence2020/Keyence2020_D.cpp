#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int cntNumberOfDigits(int N)
{
  int num = N;
  int cnt = 0;
  while (num > 0)
  {
    num /= 10;
    cnt++;
  }
  return cnt;
}

int topOfDigits(int N)
{
  int num = N;
  string s = to_string(num);
  char c = s[0];
  int res = (int)(c - '0');
  return res;
}

int endOfDigits(int N)
{
  int num = N;
  string s = to_string(num);
  char c = s[s.size() - 1];
  int res = (int)(c - '0');
  return res;
}

int main()
{
  long long N;
  cin >> N;
  vector<vector<int>> c(10, vector<int>(10));
  for (int k = 1; k <= N; k++)
  {
    int top_digits = topOfDigits(k);
    int end_digits = endOfDigits(k);
    c[top_digits][end_digits]++;
  }
  long long ans = 0;
  for (int i = 1; i <= 9; i++)
  {
    for (int j = 1; j <= 9; j++)
    {
      ans += c[i][j] * c[j][i];
    }
  }
  cout << ans << endl;
}
