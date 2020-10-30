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

vector<int> dijkstra(Graph &G, int start)
{
    vector<int> dist(G.size(), INT_INF);
    // pair(その時点での最短経路，頂点番号)
    priority_queue<P, vector<P>, greater<P>> que;
    dist[start] = 0;
    que.push(make_pair(dist[start], start));
    while (!que.empty())
    {
        int cost = que.top().first;
        int idx = que.top().second;
        que.pop();
        if (dist[idx] < cost)
            continue;

        for (auto e : G[idx])
        {
            if (dist[e.to] <= cost + e.weight)
                continue;
            dist[e.to] = cost + e.weight;
            que.push(make_pair(dist[e.to], e.to));
        }
    }
    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    ll T;
    cin >> T;
    vector<ll> A(N);
    for (auto &it : A)
        cin >> it;

    Graph G1(N), G2(N);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G1[a].push_back({b, c});
        G2[b].push_back({a, c});
    }

    vector<int> dist1 = dijkstra(G1, 0);
    vector<int> dist2 = dijkstra(G2, 0);

    ll ans = T * A[0];
    for (int i = 1; i < N; i++)
    {
        if (dist1[i] == INT_INF || dist2[i] == INT_INF)
            continue;
        ll tmp = A[i] * (T - (dist1[i] + dist2[i]));
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}

// どの町を経由するかでループを回す．都市0からのコストを計算する．
// 全ての頂点から町1までの最短経路を調べているとTLEしてしまうので町1から辺を逆向きにたどることを考える．頂点iから頂点1への最短距離というのは頂点1から辺を逆向きにたどったときの頂点iへの最短距離と言い換えられる．
// 各頂点について頂点1からの最短距離を辺の向きがそのままの場合と辺の向きを逆転した場合について求める．ここから各頂点に滞在可能な最大の時間を求めて，所持金の最大値を全探索する．
