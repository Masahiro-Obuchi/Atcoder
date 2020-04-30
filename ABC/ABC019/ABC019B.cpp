#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  vector<string> S;
  string temp;
  temp += s[0];
  for (int i = 1; i < s.size(); i++)
  {
    if (s[i] == s[i - 1])
    {
      temp += s[i];
    }
    else
    {
      S.push_back(temp);
      temp = "";
      temp += s[i];
    }
  }
  S.push_back(temp);
  for (int i = 0; i < S.size(); i++)
  {
    S[i] = S[i][0] + to_string(S[i].size());
  }
  for (int i = 0; i < S.size(); i++)
  {
    cout << S[i];
  }
  cout << endl;
}
