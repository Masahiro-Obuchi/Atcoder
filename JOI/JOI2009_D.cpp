#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int k;
  cin >> k;
  vector<string> number(n);
  for (int i = 0; i < n; i++)
  {
    cin >> number[i];
  }
  sort(number.begin(), number.end());
  set<string> st;
  do
  {
    string tmp;
    for (int i = 0; i < k; i++)
    {
      tmp += number[i];
    }
    st.insert(tmp);
  } while (next_permutation(number.begin(), number.end()));
  cout << st.size() << endl;
}
