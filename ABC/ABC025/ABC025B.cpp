#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, A, B;
  cin >> N >> A >> B;
  vector<pair<string, int>> data(N);
  for (int i = 0; i < N; i++)
  {
    string s;
    int d;
    cin >> s >> d;
    data[i] = make_pair(s, d);
  }
  int now = 0;
  for (auto itr = data.begin(); itr != data.end(); itr++)
  {
    int move = 0;
    if (itr->first == "East")
    {
      if (itr->second <= B and itr->second >= A)
        move += itr->second;
      else if (itr->second > B)
        move += B;
      else
        move += A;
    }
    else
    {
      if (itr->second <= B and itr->second >= A)
        move -= itr->second;
      else if (itr->second > B)
        move -= B;
      else
        move -= A;
    }
    now += move;
  }
  if (now < 0)
    cout << "West"
         << " " << -now << endl;
  else if (now > 0)
    cout << "East"
         << " " << now << endl;
  else
    cout << 0 << endl;
}
