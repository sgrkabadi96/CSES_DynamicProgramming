#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    ll sum = (n * (n + 1)) / 2;
    ll req = sum / 2;
    ll dp[n + 1][req + 1];
    memset(dp, 0, sizeof dp);

    if (sum % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    else
    {  
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= req; j++)
            {
                dp[i][j] = dp[i - 1][j] % MOD;
                if (j - i >= 0)`x
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
                }
                if (j <= req - i)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][req - i]) % MOD;
                }
            }
        }
    }

    cout << (dp[n][req] % MOD) / 2 % MOD << endl;

    return 0;
}
