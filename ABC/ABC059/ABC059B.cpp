#include <bits/stdc++.h>
using namespace std;

int main()
{
  string A, B;
  cin >> A >> B;
  if (A.size() > B.size())
    cout << "GREATER" << endl;
  else if (A.size() < B.size())
    cout << "LESS" << endl;
  else
  {
    bool equal = true;
    for (int i = 0; i < A.size(); i++)
    {
      if (A[i] - '0' > B[i] - '0')
      {
        cout << "GREATER" << endl;
        equal = false;
        break;
      }
      else if (A[i] - '0' < B[i] - '0')
      {
        cout << "LESS" << endl;
        equal = false;
        break;
      }
    }
    if (equal)
      cout << "EQUAL" << endl;
  }
}
