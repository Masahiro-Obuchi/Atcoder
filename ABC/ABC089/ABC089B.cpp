#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  set<char> st;
  while (N--)
  {
    char c;
    cin >> c;
    st.insert(c);
  }
  if (st.size() == 4)
    cout << "Four" << endl;
  else
    cout << "Three" << endl;
}
