#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T, N;
  cin >> T >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  int M;
  cin >> M;
  vector<int> B(M);
  for (int i = 0; i < M; i++)
  {
    cin >> B[i];
  }
  if (B.size() > A.size())
    cout << "no" << endl;
  else
  {
    vector<bool> bb(M, false);
    int nowa = 0;
    for (int i = 0; i < M; i++)
    {
      bool b = false;
      while (nowa < N)
      {
        if (A[nowa] <= B[i] and B[i] - A[nowa] <= T)
        {
          b = true;
          nowa++;
          break;
        }
        nowa++;
      }
      if (b)
        bb[i] = true;
    }
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
      if (bb[i] == false)
        cnt++;
    }
    if (cnt > 0)
      cout << "no" << endl;
    else
      cout << "yes" << endl;
  }
}

// Bの各要素に対してマッチングしたかどうかを保持するvectorを作る．条件を満たせばtrueにする．また見ているAの要素をnowaで保持し，whileでインクリメントしながら比較する．nowaがN以上になってしまったらアウト．AもBも前から見ていく．
