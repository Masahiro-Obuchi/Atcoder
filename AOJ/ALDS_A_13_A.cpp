#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;
const long long INF = 1LL << 60;

#define N 8
#define FREE -1
#define NOT_FREE 1

int row[N], col[N], dpos[2 * N - 1], dneg[2 * N - 1];

bool X[N][N];

void initialize()
{
  for (int i = 0; i < N; i++)
    row[i] = FREE, col[i] = FREE;
  for (int i = 0; i < 2 * N - 1; i++)
    dpos[i] = FREE, dneg[i] = FREE;
}

void printBoard()
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (X[i][j])
      {
        if (row[i] != j)
          return; // 前提としてコマが置かれているのに探索の結果ではコマが置かれていない場合．
      }
    }
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << ((row[i] == j) ? "Q" : ".");
    }
    cout << endl;
  }
}

void recursive(int i)
{
  if (i == N)
  { // クイーンの襲撃に成功
    printBoard();
    return;
  }

  for (int j = 0; j < N; j++)
  {
    // (i, j)が他のクイーンに襲撃されている場合は無視
    if (NOT_FREE == col[j] || NOT_FREE == dpos[i + j] || NOT_FREE == dneg[i - j + N - 1])
      continue;
    // (i, j)にクイーンを配置する
    row[i] = j;
    col[j] = dpos[i + j] = dneg[i - j + N - 1] = NOT_FREE;
    // 次の行を試す
    recursive(i + 1);
    // (i, j)に配置されているクイーンを取り除く
    row[i] = col[j] = dpos[i + j] = dneg[i - j + N - 1] = FREE;
  }
  // クイーンの配置に失敗
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  initialize();

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      X[i][j] = false;
    }
  }

  int k;
  cin >> k;
  for (int i = 0; i < k; i++)
  {
    int r, c;
    cin >> r >> c;
    X[r][c] = true;
  }

  recursive(0);

  return 0;
}

// バックトラック法　1行目の任意のマスにクイーンを配置する．1行目に配置したクイーンによって襲撃されない2行目のマスに，クイーンを配置する．... 各クイーンが他のどのクイーンも襲撃しないように，i個のクイーンを最初のi行に配置出来た状態で，これらのどのクイーンにも襲撃されない(i + 1)行目のマスにクイーンを配置する．-> もしも，そのようなマスが(i + 1)行目のマスに存在しなければi行目に戻り，i行目で行っていた「襲撃されないマスを探す処理」を続行する．もしそのようなマスがなければ，さらに(i - 1)行目に戻る．
// このように，可能性のある状態を体系的に試していき，現在の状態からは回が得られないと分かった時点で探索を打ち切り，一つ前の状態に戻って（途中から）探索を再開する手法をバックトラックという．
// 8クイーン問題ではマス(i, j)が他のクイーンによって襲撃されているかを記憶するために4つの配列変数を用意する．いずれかがNOT_FREEであればコマ(i, j)が襲撃されていることになる．
