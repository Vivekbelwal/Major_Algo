#include <bits/stdc++.h>

using namespace std;

int main(){
    int t {} ;cin >>t;
    while (t--){
        int n {} ; cin >> n;
        vector <int> vec (n,0);
        for (int i {} ; i<n ; i++){
            cin >> vec[i];
        }
        
        
    
    int a {vec[0] };
    int sum {};
    int water {};
    for ( int i {1} ; i < n ; i++ ){
        if ( vec[i]<a ){
            sum+=a-vec[i];
        }
        else if ( vec[i]>=a ){
            a=vec[i];
            water+=sum;
            sum=0;
        }
    }
    if ( sum!=0 ){
        sum = 0;
        int b {vec[n-1]} ;
        for (int i {n-2}; i>=0 ; i-- ){
            if (vec[i]<b){
                sum+=b-vec[i];
            }
            else if ( vec[i]>=b ){
                b=vec[i];
                water+=sum;
                sum=0;
            }
            if (b==a)break;
        }
    }
    cout << water << endl;
    }
    return 0;
}