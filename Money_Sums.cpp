#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    vector<vector<int>> dp(n+1 , vector<int> (sum+1 , 0 )) ; 
    dp[0][0] = 1 ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= sum ; j++){
            if(j == 0 ) {
                dp[i][j] = 1 ;
            } else if(i == 0 ) {
                dp[i][j] = 0 ;
            } else {
                int curr = 0; 
                curr = curr | dp[i-1][j];
                if(j - a[i-1] >= 0 ) {
                    curr = curr | dp[i-1][j- a[i-1]];
                }
                dp[i][j] = curr;
            }
        }
    }
    int c = 0;
    for(int i= 1 ; i <= sum ; i++){
        if(dp[n][i] == 1) c++;
    }
    cout << c<< endl;
     for(int i= 1 ; i <= sum ; i++){
        if(dp[n][i] == 1) cout << i << " ";
    }


    return 0;
}
