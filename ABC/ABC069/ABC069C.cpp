#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long int> a(N);
  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  int two = 0, four = 0;
  for (int i = 0; i < N; i++)
  {
    if (a[i] % 2 == 0 && a[i] % 4 != 0)
      two++;
    else if (a[i] % 4 == 0)
      four++;
  }
  int odd = N - two - four;
  if (two + four == N)
    cout << "Yes" << endl;
  else
  {
    if (four >= N / 2)
      cout << "Yes" << endl;
    else if (four >= (N + (2 - 1)) / 2 - two / 2)
      cout << "Yes" << endl;
    else if (four >= (N + (2 - 1)) / 2 - (two + (2 - 1)) / 2 && N % 2 != 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}

// ひとつながりの2は1と等価と見なすことが出来る．したがって2がない場合へと帰着することができ，答えはb1 <= b4となる（ひとまとまりの2があるという前提）．かなり無理やり解いてしまった．もっとコンパクトに実装できるように丁寧に実験，考察を行っていきたい．
