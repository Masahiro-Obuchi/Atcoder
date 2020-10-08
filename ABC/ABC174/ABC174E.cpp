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

int dx[4] ={ 1, 0, -1, 0 }, dy[4] ={ 0, 1, 0, -1 };
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

bool check(ll x, ll N, ll K, vector<ll> &A)
{
    ll cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] > x)
        {
            cnt++;
            cnt += (A[i] - x + (x - 1)) / x - 1;
        }
    }
    if (cnt <= K)
        return true;
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (auto &it : A)
        cin >> it;
    ll left = 0, right = INF;
    while (left + 1 < right)
    {
        ll mid = (left + right) / 2;
        if (check(mid, N, K, A))
            right = mid;
        else
            left = mid;
    }
    cout << right << endl;
    return 0;
}

// 二分探索？最小の長さを決め打ちしてそれを超える丸太を全て切っていく 最小の最大や最大の最小は二分探索
