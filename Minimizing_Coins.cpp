#include<bits/stdc++.h> 

using namespace std;

int main(){
    int n , x;
    cin >> n >> x ;
    int a[n];

    for(int i =  0 ; i < n ; i++){
        cin >> a[i];
    }

   int dp[n + 1][x + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = 1e9;
        }
    }

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j<= x ; j++){
            if(j == 0 ) {
                dp[i][j] = 0; 
            } else if(i == 0 ) {
                dp[i][j] = 1e9 ;
            } else {
                int currCoin = a[i-1];
                dp[i][j] = min(dp[i][j] , dp[i-1][j]);
                if (j - currCoin >= 0) {
                    dp[i][j] = min(dp[i][j], dp[i][j - currCoin] + 1);
                }
            }
        }
    }

    if(dp[n][x] == 1e9) {
        cout << -1 << endl;
    } else {
        cout << dp[n][x] << endl;
    }

}

