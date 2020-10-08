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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, D;
    cin >> N >> D;
    ll D_squared = D * D;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ll X, Y;
        cin >> X >> Y;
        ll dist = X * X + Y * Y;
        if (dist <= D_squared)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
