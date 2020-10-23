#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, R;
  string S;
  cin >> N >> R >> S;
  int rightIdx = 0;
  for (int i = N - 1; i >= 0; i--)
  {
    if (S[i] == '.')
    {
      rightIdx = max(rightIdx, max(0, i - R + 1));
    }
  }
  int move = rightIdx;
  int shot = 0;
  for (int i = 0; i < N; i++)
  {
    if (S[i] == '.')
    {
      for (int j = 0; j < R; j++)
      {
        S[min(N - 1, i + j)] = 'o';
      }
      shot++;
    }
  }
  int ans = move + shot;
  cout << ans << endl;
  return 0;
}

// 進まなければいけない最も右のマスを調べる->貪欲に移動して打つ　.のマスに到着した場合のみ発射
// 銃を打つ回数は・最も左にある.を探して銃を打つを繰り返すのが最善
