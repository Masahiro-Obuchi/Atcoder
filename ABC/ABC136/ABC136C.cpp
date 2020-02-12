#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++)
  {
    cin >> H.at(i);
  }
  bool can = true;
  int hi;
  if (H.at(0) >= 1)
  {
    hi = H.at(0) - 1;
  }
  else
  {
    hi = H.at(0);
  }
  int now;
  for (int i = 1; i < N; i++)
  {
    if (hi - H.at(i) >= 1)
    {
      can = false;
      break;
    }
    else
    {
      if (H.at(i) == hi)
        continue;
      else
        hi = H.at(i) - 1;
    }
  }
  if (can)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
