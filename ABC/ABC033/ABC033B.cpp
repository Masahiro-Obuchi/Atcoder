#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<pair<string, int>> p(N);
  for (int i = 0; i < N; i++)
  {
    string S;
    int P;
    cin >> S >> P;
    p[i] = make_pair(S, P);
  }
  long long int sum = 0;
  for (int i = 0; i < N; i++)
  {
    sum += p[i].second;
  }
  for (int i = 0; i < N; i++)
  {
    if (p[i].second > sum / 2)
    {
      cout << p[i].first << endl;
      return 0;
    }
  }
  cout << "atcoder" << endl;
}

// pair make_pair vectorの使い方
