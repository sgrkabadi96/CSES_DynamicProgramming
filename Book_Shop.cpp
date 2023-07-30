#include<bits/stdc++.h>


using namespace std;

int main(){
    int n , x;
    cin >> n >> x ;

    int price[n];
    int pages[n];

    for(int i = 0 ; i < n ; i++){
        cin >> price[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin >> pages[i];
    }

    vector<vector<int>> dp(n +1 , vector<int> (x+1 , 0 ) );
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= x ; j++){
            if(i == 0 ) dp[i][j] = 0 ;
            else if(j == 0 ) {
                dp[i][j] = 0 ;
            } else {
                dp[i][j] = dp[i-1][j];
                int currPrice = price[i-1];
                int currPages = pages[i-1];
                if(currPrice <= j ) {
                    dp[i][j] = max(dp[i][j] , dp[i-1][j - currPrice]  + currPages) ;
                }
            }
        }
    }

    cout << dp[n][x] << endl;
}