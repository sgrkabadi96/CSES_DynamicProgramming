#include<bits/stdc++.h>

using namespace std ;

int main(){
    int n  ;
    cin >> n ;

    int dp[n+1] = {0};
    int mod = 1e9+ 7 ;

    dp[0] = 1 ;
    for(int i = 1 ; i <= n ; i++){
        if(i == 1 ) {
            dp[i] = 1 ;
        } else {
            for(int j = 1 ; j <= 6 ; j++){
                if(i - j >= 0 ) {
                    dp[i] = (dp[i] + dp[i  - j]) % mod;
                }
            }
        }
    }
    cout << dp[n] % mod << endl;
}