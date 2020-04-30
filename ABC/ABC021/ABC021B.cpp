#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  set<int> st;
  int a, b;
  cin >> a >> b;
  st.insert(a);
  st.insert(b);
  int K;
  cin >> K;
  vector<int> P(K);
  for (auto p : P)
  {
    cin >> p;
    st.insert(p);
  }
  if (st.size() != K + 2)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
