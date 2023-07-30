#include<bits/stdc++.h>

using namespace std ;

int  main() {
    string s ;
    string x ;
    cin >> s >> x ; 
    int n = s.size();
    int m = x.size();

    vector<vector<int>> dp(n+1 , vector<int> (m + 1 , 0 ));


    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            if(i == 0 ) {
                dp[i][j] = j ;
            } else if(j == 0  ) {
                dp[i][j] = i ;
            } else if(s[i-1] == x[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = dp[i][j-1] + 1;
                dp[i][j] = min(dp[i][j] , dp[i-1][j] + 1 );
                dp[i][j] = min(dp[i][j] ,dp[i-1][j-1] + 1) ;
            }
        }
    }   

    cout << dp[n][m] << endl;

}