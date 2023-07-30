#include<bits/stdc++.h>
using namespace std;

int helper(int n  ,int *dp) {
    if(n == 0 ) return 0 ;
    if(n < 0 ) return 0 ;
    int curr = n ; 
    int ans = 1e9;
    if(dp[n] != -1 ) return dp[n];
    while(curr > 0  ) {
        int r = curr % 10 ; 
        curr = curr / 10 ;
        if(r == 0 ) continue;
        ans = min(ans , helper(n - r , dp) + 1 ); 
    }
    return dp[n] =  ans;
}

int main(){
    int n ;
    cin >> n ;

    int dp[n+1];
    memset(dp , 0 , sizeof dp);
    dp[0] = 0 ;
   
    for(int i = 1 ; i <= n ; i++){
        int curr = i ;
        int ans = 1e9 ;
        while(curr > 0  ){
            int r = curr % 10 ; 
            curr = curr / 10 ; 
            if(r == 0 ) continue;
            if(i - r >= 0 ) {
                ans = min(ans , dp[i-r] + 1 );
            }
        }
        dp[i] = ans ;
    }
    cout << dp[n];

}