#include <bits/stdc++.h>
using namespace std;

bool vector_finder(vector<int> vec, int number)
{
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance(vec.begin(), itr);
  if (index != vec.size())
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int main()
{
  int N, M;
  cin >> N >> M;
  vector<vector<int>> data(200000);
  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    data[a].push_back(b);
  }
  bool can = false;
  for (auto v : data[0])
  {
    if (vector_finder(data[v], N - 1))
    {
      can = true;
      break;
    }
  }
  if (can)
    cout << "POSSIBLE" << endl;
  else
    cout << "IMPOSSIBLE" << endl;
}

// コメント
// 島1とiに辺があるかを格納するbool配列と島Nと島iに辺があるかを格納するbool配列を用意して共にtrueだったら条件を満たすみたいな解き方の方が早かったかも
