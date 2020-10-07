#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W;
  string S;
  cin >> S;
  bool can = true;
  reverse(S.begin(), S.end());
  cerr << S << endl;
  vector<string> candidate{"dream", "dreamer", "erase", "eraser"};
  for (auto &s : candidate)
    reverse(s.begin(), s.end()), cerr << s << endl;

  int i = 0;
  while (i < S.size())
  {
    if (S[i] == 'm')
    {
      if (S.substr(i, 5) == candidate[0])
        i += 5;
      else
      {
        can = false;
        break;
      }
    }
    else if (S[i] == 'e')
    {
      if (S.substr(i, 5) == candidate[2])
        i += 5;
      else
      {
        can = false;
        break;
      }
    }
    else if (S[i] == 'r')
    {
      cerr << "a" << endl;
      if (S[i + 1] != 'e')
      {
        cerr << "b" << endl;
        can = false;
        break;
      }
      else
      {
        if (S[i + 2] == 'm')
        {
          if (S.substr(i, 7) == candidate[1])
            i += 7;
          else
          {
            cerr << "c" << endl;
            can = false;
            break;
          }
        }
        else if (S[i + 2] == 's')
        {
          cerr << S.substr(i, 6) << " " << candidate[3] << endl;
          if (S.substr(i, 6) == candidate[3])
            i += 6;
          else
          {
            cerr << "d" << endl;
            can = false;
            break;
          }
        }
        else
        {
          cerr << "e" << endl;
          can = false;
          break;
        }
      }
    }
  }
  if (can)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
