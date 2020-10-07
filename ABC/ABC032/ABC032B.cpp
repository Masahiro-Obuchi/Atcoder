#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int k;
  cin >> k;
  if (k > s.size())
    cout << 0 << endl;
  else
  {
    set<string> st;
    for (int i = 0; i <= s.size() - k; i++)
    {
      string substr = s.substr(i, k);
      st.insert(substr);
    }
    cout << st.size() << endl;
  }
}
