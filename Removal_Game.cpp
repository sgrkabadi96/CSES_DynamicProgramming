#include<bits/stdc++.h>
#define ll long long

using namespace std ;

long long dp[5001][5001] ; 

long long tabulatedHelper(int n, int *a){
    for (int i = 0; i < n; i++)
        dp[i][i] = a[i];
    
    for (int gap = 1; gap < n; gap++){
        for (int i = 0, j = gap; j < n; i++, j++){
            long long x = (i + 2 <= j) ? dp[i + 2][j] : 0;
            long long y = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
            long long z = (i <= j - 2) ? dp[i][j - 2] : 0;

            long long one = min(x, y) + a[i];
            long long two = min(y, z) + a[j]; 

            dp[i][j] = max(one, two);
        }
    }

    return dp[0][n - 1];
}

int main(){
    int n ;
    cin >> n ;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    memset(dp, -1, sizeof dp);
    long long result = tabulatedHelper(n, a);
    cout << result << endl;

    return 0;
}
