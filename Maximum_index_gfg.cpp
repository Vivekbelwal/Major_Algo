#include <iostream>
#include <vector>
using namespace std;

int maximum_index( vector <int> vec ){
    int n {vec.size()};
    vector <int> l (n,0);
    vector <int> r (n,0);
    int max_diff {-1};
    
    l[0] = vec[0];
    for ( int i {1} ; i<n ; i++ ){
        l[i] = l[i-1]<vec[i]? l[i-1]:vec[i];
    } 
    
    r[n-1]= vec[n-1];
    for ( int i {n-2} ; i>-1 ; i-- ){
        r[i] = r[i+1]>vec[i]?r[i+1]:vec[i];
    }
    
    
    int i {};
    int j {};
    while (i<n && j<n){
        if ( l[i]<=r[j] ){
            max_diff = max_diff>j-i?max_diff:j-i;
            j++;
        }
        
        else{
            i++;
        }
    }
    return max_diff;
    
}



int main() {
	//code
	int t {}; cin >> t;
	while (t--){
	int n {} ; 
	cin >> n;
	vector <int> vec (n,0);
	for ( int i {} ; i < n ; i++ ){
	    cin >> vec[i];
	}
	cout << maximum_index( vec ) << endl;
	}
	return 0;
}