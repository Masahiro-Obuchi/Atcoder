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
    int N;
    cin >> N;
    string c;
    cin >> c;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < N; i++) {
        if (c[i] == 'R')
            cnt1++;
        if (c[i] == 'W')
            cnt2++;
    }

    int lidx = 0, ridx = N - 1;
    int cnt3 = 0;
    while (lidx < ridx) {
        bool findWhite = false;
        if (c[lidx] == 'W') {
            findWhite = true;
        }
        if (findWhite && c[ridx] == 'R') {
            swap(c[lidx], c[ridx]);
            cnt3++;
            lidx++, ridx--;
        }
        else if (findWhite && c[ridx] == 'W') {
            ridx--;
        }
        else {
            lidx++;
        }
    }
    cout << min(cnt1, min(cnt2, cnt3)) << endl;
    return 0;
}
