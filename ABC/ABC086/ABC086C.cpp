#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<vector<int>> data(N, vector<int>(3));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> data.at(i).at(j);
    }
  }
  bool can = true;
  for (int i = 0; i < N; i++)
  {
    int t, distance;
    t = data.at(i).at(0);
    distance = data.at(i).at(1) + data.at(i).at(2);
    if (t % 2 != distance % 2)
    {
      can = false;
      break;
    }
  }
  if (data.at(0).at(0) < data.at(0).at(1) + data.at(0).at(2))
    can = false;
  for (int i = 0; i < N - 1; i++)
  {
    int deltat, deltad;
    deltat = data.at(i + 1).at(0) - data.at(i).at(0);
    deltad = abs((data.at(i + 1).at(1) + data.at(i + 1).at(2)) - (data.at(i).at(1) + data.at(i).at(2)));
    if (deltad > deltat)
    {
      can = false;
      break;
    }
  }
  if (can)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
