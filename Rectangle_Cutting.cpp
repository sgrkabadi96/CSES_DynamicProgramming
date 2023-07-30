#include<bits/stdc++.h>

using namespace std ;

int dp[501][501];

int helper(int a ,int b ) {
    if(a == b ) return 0 ;
    if(dp[a][b] != -1) return dp[a][b];
    int ans = 1e9; 
    for(int  i = 1 ; i <= a /2  ; i++) {
        ans = min(ans , helper(a - i , b ) + helper(i , b) + 1 );     
    }
    for(int j = 1 ; j <= b/2 ; j++){
        ans = min(ans , helper(a , b-j) + helper(a , j) + 1 );
    }
    return dp[a][b]= ans;
}

int main(){
    int a , b ; 
    cin >> a >> b ;
    memset(dp , 1e9  , sizeof dp);

    // cout << helper(a , b );

    for(int i = 1 ;  i <= a ; i++){
        for(int j = 1 ; j <= b ; j++){
            if(i==j ) {\
                dp[i][j] =  0;
            } else {
                int ans = 1e9;
                for(int k = 1 ; k <= i /2 ; k++) {
                    ans = min(ans, dp[k][j]+ dp[i-k][j] + 1 );
                }
                  for(int k = 1 ; k <= j /2 ; k++) {
                    ans = min(ans, dp[i][k]+ dp[i][j - k] + 1 );
                }
                dp[i][j] = ans;
            }
        }
    }

    cout << dp[a][b] << endl;
}