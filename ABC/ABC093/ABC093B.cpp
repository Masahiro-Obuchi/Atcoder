#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B, K;
  cin >> A >> B >> K;
  set<int> st;
  for (int i = 0; i < K; i++)
  {
    if (A + i <= B)
    {
      st.insert(A + i);
    }
    if (B - i >= A)
    {
      st.insert(B - i);
    }
  }

  for (auto itr = st.begin(); itr != st.end(); itr++)
  {
    cout << *itr << endl;
  }
}
