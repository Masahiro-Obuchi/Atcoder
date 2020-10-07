#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<string> W(N);
  for (int i = 0; i < N; i++)
  {
    cin >> W[i];
  }
  bool ans = true;
  for (int i = 1; i < N; i++)
  {
    if (W[i][0] != W[i - 1].back())
    {
      ans = false;
      break;
    }
    for (int j = 0; j < i; j++)
    {
      if (W[i] == W[j])
      {
        ans = false;
        break;
      }
    }
  }
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
