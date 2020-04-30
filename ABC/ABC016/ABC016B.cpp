#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    bool plus = false;
    bool minus = false;
    if (A + B == C) plus = true;
    if (A - B == C) minus = true;
    if (plus && !minus) cout << "+" << endl;
    else if (!plus && minus) cout << "-" << endl;
    else if (plus && minus) cout << "?" << endl;
    else cout << "!" << endl;
    return 0;
}