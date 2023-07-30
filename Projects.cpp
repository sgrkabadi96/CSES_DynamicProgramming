#include <bits/stdc++.h>

#define ll long long
using namespace std;

bool comp(vector<ll> &a, vector<ll> &b)
{
    return a[1] < b[1];
}

int binarySearch(int s, int e, vector<vector<ll>> &a, ll start)
{
    int ans = -1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (a[m][1] < start)
        {
            ans = m;
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(3));

    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0];
        cin >> a[i][1];
        cin >> a[i][2];
    }
    sort(a.begin(), a.end(), comp);

    vector<ll> dp(n);
    dp[0] = a[0][2];

    for (int i = 1; i < n; i++)
    {
        ll op1 = dp[i - 1];
        ll op2 = a[i][2];
        ll idx = binarySearch(0, i - 1, a, a[i][0]);
        if (idx != -1)
        {
            op2 += dp[idx];
        }
        dp[i] = max(op1, op2);
    }

    cout << dp[n - 1];
    return 0;
}
