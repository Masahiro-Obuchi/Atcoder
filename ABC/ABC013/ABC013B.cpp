#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int ans1, ans2;
    ans1 = 0; ans2 = 0;
    ans1 = abs(a - b);
    if (a >= b) ans2 = b + 9 - a + 1;
    else ans2 = a + 9 - b + 1;
    int ans = min(ans1, ans2);
    cout << ans << endl;
}