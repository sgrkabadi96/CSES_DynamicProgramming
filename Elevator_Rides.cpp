#include<bits/stdc++.h>

using namespace std ;

int dp[21];

int helper(int idx , int *a , int n, vector<int> &v, int x ) {
    if(idx >= n  ) return v.size();
    int ans = 1e9 ;
    if(dp[idx] != -1 ) return dp[idx];
    for(int i = 0 ; i < v.size() ; i++){
        if(v[i] + a[idx] <= x ) {
            v[i]+= a[idx];
            ans = min(ans , helper(idx +1 , a , n , v , x ) );
            v[i]-= a[idx];
        }
    }
    v.push_back(a[idx]);
    ans = min(ans , helper(idx + 1  , a , n , v , x ));
    v.pop_back();

    return dp[idx] =  ans;

}


int main() {
    int n , x ; 
    cin >> n >> x ; 


    int a[n];

    for(int i = 0 ; i < n ; i++){
        cin >> a[ i];
    }

    vector<int> v(1); 
    memset(dp , -1 , sizeof dp);
    cout << helper(0 ,a , n , v ,x );
}