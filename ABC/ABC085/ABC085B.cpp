#include <bits/stdC++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  set<int> st;
  while (N--)
  {
    int d;
    cin >> d;
    st.insert(d);
  }
  cout << st.size() << endl;
}
