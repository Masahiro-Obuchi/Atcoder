#include <bits/stdc++.h>
using namespace std;

string padding(string str);

int main()
{
  int N, M;
  cin >> N >> M;

  vector<tuple<int, int, int>> PY;
  for (int i = 0; i < M; i++)
  {
    int p, y;
    cin >> p >> y;

    PY.emplace_back(p, y, i); // 要素構築
  }

  sort(PY.begin(), PY.end());

  vector<string> ID(M);
  int cnt = 1;

  ID[get<2>(PY[0])] = padding(to_string(get<0>(PY[0]))) + padding(to_string(cnt));

  for (int i = 1; i < M; i++)
  {
    if (get<0>(PY[i]) != get<0>(PY[i - 1]))
      cnt = 1;
    else
      cnt++;

    ID[get<2>(PY[i])] = padding(to_string(get<0>(PY[i]))) + padding(to_string(cnt));
  }

  for (int i = 0; i < M; i++)
  {
    cout << ID[i] << endl;
  }

  return 0;
}

string padding(string str)
{
  int zeros = 6 - (int)str.size();

  for (int i = 0; i < zeros; i++)
  {
    str = "0" + str;
  }
  return str;
}
