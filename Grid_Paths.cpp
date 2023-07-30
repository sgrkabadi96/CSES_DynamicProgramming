#include<bits/stdc++.h>

using namespace std ;

int main(){
    int n ;
    cin >> n ;
    char a[n][n];

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> a[i][j];
        }
    }

    int dp[n+1][n+1] ;

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j  <= n ; j++){
            dp[i][j] = 0;
        }
    }
    int mod = 1e9 + 7 ; 

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j ++){
            char x  = a[i-1][j-1];
            if(x == '*') continue;
            if(i == 1 && j == 1) dp[i][j] = 1;
            else {
                
                if(x  == '.'){
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
                }
            }
        }
    }
    cout << dp[n][n] << endl;
}