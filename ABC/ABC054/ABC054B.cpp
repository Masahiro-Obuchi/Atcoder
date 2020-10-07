#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<string> A(N);
  vector<string> B(M);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  for (int i = 0; i < M; i++)
  {
    cin >> B[i];
  }

  bool exist = false;

  for (int ly = 0; ly < N; ly++)
  {
    for (int lx = 0; lx < N; lx++)
    {
      if (ly >= N - M + 1 or lx >= N - M + 1)
        continue;

      bool match = true;
      for (int y = 0; y < M; y++)
      {
        for (int x = 0; x < M; x++)
        {
          if (A[ly + y][lx + x] != B[y][x])
            match = false;
        }
      }
      if (match)
        exist = true;
    }
  }
  if (exist)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}

// 四重ループを使うという発想は合っていそう．まず画像Aの中におけるM×Mの正方形領域とテンプレート画像Bの同一判定は，二重ループで行うことが可能である．次に，画像Aの中におけるM×Mの正方形領域は何通りあるかを考える．これは(N - M + 1) × (N - M + 1)通り考えられる．以上のことから，全探索を行った時の時間計算量はO(N^2M^2)となり，これは間に合う．
