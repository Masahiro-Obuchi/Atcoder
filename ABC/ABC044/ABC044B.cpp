#include <bits/stdc++.h>
using namespace std;

int main()
{
  string w;
  cin >> w;
  bool good = true;
  vector<int> cnt(200);
  for (int i = 0; i < w.size(); i++)
  {
    cnt[w.at(i)]++;
  }
  for (int i = 0; i < cnt.size(); i++)
  {
    if (cnt[i] % 2 != 0)
    {
      good = false;
    }
  }
  if (good)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
