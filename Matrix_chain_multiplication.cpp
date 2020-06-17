#include <bits/stdc++.h>

using namespace std;

int mcm ( vector<int> &arr ){
    int n { arr.size() };
    vector < vector<int> > dp ( n , vector<int>( n,0 ) );
    int temp{}, j{};
    for ( int l {2} ; l<n ;l++ ){
        
        for ( int i {1} ; i < n-l+1 ; i++ ){
            j = i+l-1;
            dp [i][j] = INT_MAX;
            for ( int k {i} ; k< j ; k++  ){
                temp = dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                if ( temp<dp[i][j] ){
                    dp[i][j]=temp;
                }  
            }
        }
    
    }
    
    return dp[1][n-1];
    
}

int main(){
    int t {} ; cin >>t;
    while (t--){
        int n {} ; cin >>n;
        vector <int> arr (n,0);
        for ( int i{} ; i < n ; i++ ){
            cin >> arr[i];
        }
        cout << mcm(arr) << endl;
    }
    
    return 0;
}