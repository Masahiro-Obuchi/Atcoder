#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
  int N, M;
  cin >> N >> M;
  priority_queue<long long> que;
  for (int i = 0; i < N; i++)
  {
    long long A;
    cin >> A;
    que.push(A);
  }
  for (int i = 0; i < M; i++)
  {
    long long t = que.top();
    que.pop();
    que.push(t / 2);
  }
  long long ans = 0;
  while (!que.empty())
    ans += que.top(), que.pop();
  cout << ans << endl;
}

// 方針は合っている．実装はこのままやると間に合わないので優先度付きキューを用いる．
/*
priority_queue<int>  que;  //最大値から出てくるヒープ

priority_queue< int, vector<int>, greater<int> > que; //最小値から出てくるヒープ

que.push(); //要素の追加
que.top();  //先頭をみる
que.pop();  //先頭を削除
*/
// 最大値をpopして，2で割って，またpushする
