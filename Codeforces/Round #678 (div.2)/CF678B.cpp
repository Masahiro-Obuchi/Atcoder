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

bool isPrime(long long num)
{
    if (num < 2)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false;

    double sqrtNum = sqrt(num);

    for (int i = 3; i <= (int)sqrtNum; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

void solve()
{
    int n;
    cin >> n;
    if (isPrime(n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << 1 << " ";
            }
            cout << endl;
        }
    }
    else
    {
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            int cur = i;
            ans[i][cur]++;
            cur++;
            cur %= n;
            ans[i][cur]++;
            cur++;
            cur %= n;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}
l
