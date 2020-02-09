#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int N;
  cin >> N;
  long long int rem = N % 30;
  int quo = rem / 5;
  int rem2 = rem % 5;
  int item = quo + 1;
  vector<int> a;
  if (quo == 0)
  {
    a = {2, 3, 4, 5, 6};
  }
  else if (quo == 1)
  {
    a = {3, 4, 5, 6, 1};
  }
  else if (quo == 2)
  {
    a = {4, 5, 6, 1, 2};
  }
  else if (quo == 3)
  {
    a = {5, 6, 1, 2, 3};
  }
  else if (quo == 4)
  {
    a = {6, 1, 2, 3, 4};
  }
  else
  {
    a = {1, 2, 3, 4, 5};
  }
  auto it = a.begin();
  a.insert(it + rem2, item);
  for (int i = 0; i < 6; i++)
  {
    cout << a[i];
  }
  cout << endl;
}
// mod30を取ることで一意に定まる.N %= 30とでもした後にC++の普通のswap関数などで実際に交換してあげればよい．
