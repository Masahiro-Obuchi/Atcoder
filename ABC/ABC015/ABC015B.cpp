#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cnt = 0;
    int sum = 0;
    int ans = 0;
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        if (A[i] != 0)
        {
            cnt++;
            sum += A[i];
        }
    }
    ans = (sum + (cnt - 1)) / cnt;
    cout << ans << endl;
}
