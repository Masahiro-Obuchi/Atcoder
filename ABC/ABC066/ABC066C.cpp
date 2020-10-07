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
  list<long long int> b;
  for (int i = 0; i < N; i++)
  {
    if (i % 2 == 0)
    {
      b.push_back(a[i]);
    }
    else
    {
      b.push_front(a[i]);
    }
  }
  if (N % 2 != 0)
    b.reverse();
  for (auto itr = b.begin(); itr != b.end(); itr++)
  {
    cout << *itr << " ";
  }
  cout << endl;
}

// 偶奇に着目して各操作で前に挿入するか後ろに挿入するかを決め，Nの値によって最後にreverceするかどうかを決めればよい（実験すれば容易に確かめられる）
