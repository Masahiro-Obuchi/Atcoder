#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
/*
struct Edge
{
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
*/
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

void bfs(Graph &G, vector<int> &dist)
{
    for (auto &it : dist)
        it = -1;
    queue<int> que;
    dist[0] = 0;
    que.push(0);
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        for (auto nv : G[v])
        {
            if (dist[nv] != -1)
                continue;

            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int w, h;
    while (true)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;

        vector<vector<int>> ver(h, vector<int>(w - 1));
        vector<vector<int>> hor(h - 1, vector<int>(w));
        for (int i = 0; i < 2 * h - 1; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < w - 1; j++)
                {
                    cin >> ver[i / 2][j];
                }
            }
            else
            {
                for (int j = 0; j < w; j++)
                {
                    cin >> hor[i / 2][j];
                }
            }
        }

        Graph G(w * h);
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (i == 0)
                {
                    if (j == 0)
                    {
                        if (!ver[i][j])
                            G[w * i + j].push_back(w * i + j + 1);
                        if (!hor[i][j])
                            G[w * i + j].push_back(w * (i + 1) + j);
                    }
                    else if (j == w - 1)
                    {
                        if (!ver[i][j - 1])
                            G[w * i + j].push_back(w * i + j - 1);
                        if (!hor[i][j])
                            G[w * i + j].push_back(w * (i + 1) + j);
                    }
                    else
                    {
                        if (!ver[i][j])
                            G[w * i + j].push_back(w * i + j + 1);
                        if (!ver[i][j - 1])
                            G[w * i + j].push_back(w * i + j - 1);
                        if (!hor[i][j])
                            G[w * i + j].push_back(w * (i + 1) + j);
                    }
                }
                else if (i == h - 1)
                {
                    if (j == 0)
                    {
                        if (!ver[i][j])
                            G[w * i + j].push_back(w * i + j + 1);
                        if (!hor[i - 1][j])
                            G[w * i + j].push_back(w * (i - 1) + j);
                    }
                    else if (j == w - 1)
                    {
                        if (!ver[i][j - 1])
                            G[w * i + j].push_back(w * i + j - 1);
                        if (!hor[i - 1][j])
                            G[w * i + j].push_back(w * (i - 1) + j);
                    }
                    else
                    {
                        if (!ver[i][j])
                            G[w * i + j].push_back(w * i + j + 1);
                        if (!ver[i][j - 1])
                            G[w * i + j].push_back(w * i + j - 1);
                        if (!hor[i - 1][j])
                            G[w * i + j].push_back(w * (i - 1) + j);
                    }
                }
                else
                {
                    if (j == 0)
                    {
                        if (!ver[i][j])
                            G[w * i + j].push_back(w * i + j + 1);
                        if (!hor[i - 1][j])
                            G[w * i + j].push_back(w * (i - 1) + j);
                        if (!hor[i][j])
                            G[w * i + j].push_back(w * (i + 1) + j);
                    }
                    else if (j == w - 1)
                    {
                        if (!ver[i][j - 1])
                            G[w * i + j].push_back(w * i + j - 1);
                        if (!hor[i - 1][j])
                            G[w * i + j].push_back(w * (i - 1) + j);
                        if (!hor[i][j])
                            G[w * i + j].push_back(w * (i + 1) + j);
                    }
                    else
                    {
                        if (!ver[i][j])
                            G[w * i + j].push_back(w * i + j + 1);
                        if (!ver[i][j - 1])
                            G[w * i + j].push_back(w * i + j - 1);
                        if (!hor[i - 1][j])
                            G[w * i + j].push_back(w * (i - 1) + j);
                        if (!hor[i][j])
                            G[w * i + j].push_back(w * (i + 1) + j);
                    }
                }
            }
        }

        vector<int> dist(w * h, -1);
        bfs(G, dist);
        if (dist[w * h - 1] == -1)
            cout << 0 << endl;
        else
            cout << dist[w * h - 1] + 1 << endl;
    }
    return 0;
}

// 各マスをグラフの頂点をみなす．壁がない方向にだけ辺を張る　グラフの頂点番号はw * i + jとする．
