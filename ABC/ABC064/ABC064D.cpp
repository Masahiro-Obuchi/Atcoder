#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  string S;
  cin >> N >> S;
  int num1 = 0, num2 = 0;
  for (int i = 0; i < N; i++)
  {
    if (S[i] == '(')
      num1++;
    else if (S[i] == ')' && num1 > 0)
      num1--;
  }
  for (int i = N - 1; i >= 0; i--)
  {
    if (S[i] == ')')
      num2++;
    else if (S[i] == '(' && num2 > 0)
      num2--;
  }
  string left, right;
  for (int i = 0; i < num1; i++)
    right += ")";
  for (int i = 0; i < num2; i++)
    left += "(";
  cout << left + S + right << endl;
  return 0;
}

// 前と後ろから()の数を数えていく 足りない分だけ足していく
