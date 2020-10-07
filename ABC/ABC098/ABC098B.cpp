#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  string S;
  cin >> S;
  int max_cnt = 0;
  for (int i = 1; i < N - 1; i++)
  {
    int cnt = 0;
    string X = S.substr(0, i);
    string Y = S.substr(i, N - i);
    set<char> st;
    for (int k = 0; k < X.size(); k++)
    {
      st.insert(X[k]);
    }
    for (auto x : st)
    {
      if (Y.find(x) != string::npos)
        cnt++;
    }
    max_cnt = max(cnt, max_cnt);
  }
  cout << max_cnt << endl;
}
