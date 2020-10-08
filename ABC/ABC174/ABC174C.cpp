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
// using Graph = vector<vector<Edge>>;
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int K;
    cin >> K;
    int ans = -1;
    int modK = 7 % K;
    if (modK == 0)
        cout << 1 << endl;
    else
    {
        for (int i = 1; i < K; i++)
        {
            modK = ((modK * 10) % K + 7) % K;
            if (modK == 0)
            {
                ans = i + 1;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

// 問題は「ai=0 mod Kとなる最小のiを求めよ」と読み替えることが出来る．したがって，aiはmod Kで考えれば良いことが分かる．数列は次の漸化式で計算できる．
// ai = 7 mod K (i = 1), 10ai-1 + 7 mod K (i >= 2) この漸化式にしたがって計算することで数列のN項目までのmod K での値をO(N)で求めることが出来る．また，この漸化式よりaiに同じ値が出るとその先は繰り返しになることが分かる．よって，鳩ノ巣原理より高々K項目までを計算すれば十分であることが分かる．
