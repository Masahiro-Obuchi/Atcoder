#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
// using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N, A, B;
  cin >> N >> A >> B;
  if (N <= A)
    cout << "Takahashi" << endl;
  else if (A == B)
  {
    if (N % (A + 1) == 0)
    {
      cout << "Aoki" << endl;
    }
    else
      cout << "Takahashi" << endl;
  }
  else
  {
    if (N - 1 <= B)
      cout << "Aoki" << endl;
    else if (N - 1 > B && A < B)
      cout << "Aoki" << endl;
    else
      cout << "Takahashi" << endl;
  }
  return 0;
}

// (A == Bのとき)NをA+1で割った余りが0のとき青木さんは常に自分の番にA + 1の倍数になるように取ることが出来る．つまり最終的に取ることが出来る．逆にそれ以外の時高橋さんは自分の番の時にA + 1の倍数にし続けることが出来るので絶対に勝つことが出来る．
// A > BのときN > Aの時を考える．先手が一個の石を取ったとき後手がどのように石を取ったとしても再び先手の番が訪れる．(B < Aだから)N - 1 > A - 1 >= Bより明らか　いずれN <= Aの盤面で先手の番が訪れるので先手必勝．A < Bのときを考える．このとき残りの石の数NについてN<=Bならば後手の勝利．N > B(A < Bだから)のとき後手が1個の石を取ったとき先手がどのように取ったとしても再び後手の番が訪れる．いずれN<=Bの盤面で後手の番が訪れるので後手必勝
