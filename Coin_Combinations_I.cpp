#include <iostream>
using namespace std;

const int mod = 1e9 + 7;
const int MAXN = 1000001; // Change this value according to the maximum possible value of x.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int dp[MAXN] = {0};
    dp[0] = 1;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - a[j] >= 0)
            {
                dp[i] = (dp[i] + dp[i - a[j]]) % mod;
            }
        }
    }

    cout << dp[x] << endl;
    return 0;
}
