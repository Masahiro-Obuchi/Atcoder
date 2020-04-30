#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, X;
    cin >> n >> X;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (X & (1 << i))
        {
            sum += a[i];
        }
    }
    cout << sum << endl;
    return 0;
}
