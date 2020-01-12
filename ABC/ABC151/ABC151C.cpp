
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<bool> AC(N, 0);
  vector<int> WA(N, 0);
  int ac = 0, wa = 0;
  for (int i = 0; i < M; i++)
  {
    int p;
    string S;
    cin >> p >> S;
    p--;
    if (S == "AC")
    {
      if (!AC[p])
      {
        ac++;
        wa += WA[p];
        AC[i] = true;
      }
    }
    else
      WA[p]++;
  }
  cout << ac << " " << wa << endl;
}
