#include <bits/stdc++.h>

using namespace std;

int primitive_calculator( int n ){
    vector <int> vec ( n+1 ,0 );
    vec[1]=0;
    int temp {};
    for ( int i {2} ; i <= n ;i++ ){

        int steps = numeric_limits<int>::max();
        
        if ( i>=3 && i%3==0 ){
            temp = vec[i/3]+1;
            if (temp<steps){
                steps=temp;
            }
        }
          if ( i>=2 && i%2==0 ){
            temp = vec[i/2]+1;
            if (temp<steps){
                steps=temp;

            }
        }
        if ( i>=1 ){
            temp = vec[i-1]+1;
            if (temp<steps){
                steps=temp;

            }
        }
      
        
        vec[i]=steps;
    }
    
    cout << vec[n] << endl;
    
    
// now the program to print the intermediate steps
    stack <int> stages {};
    stages.push(n);
    int i {n};
    while ( i>1 ){
        int min = numeric_limits<int> :: max();
        int b {numeric_limits<int> :: max()};
        if ( i>=3 && i%3==0 ){
            if ( vec[i/3]<=min ){
                min=vec[i/3];
                b = i/3;
            }
        }
        if ( i>=2 && i%2==0 ){
            if ( vec[i/2]<=min ){
                min=vec[i/2];
                b=i/2;
                
            }
        }
        if ( i>=1 ){
            if ( vec[i-1]<=min ){
                min=vec[i-1];
                b = i-1;
                
            }
        }
        
        i=b;
        stages.push(b);
        
    }
    while ( !stages.empty() ){
        cout << stages.top() << " ";
        stages.pop();
    }
    
}





int main(){
    int n {} ; cin >> n ; 
    primitive_calculator( n );
    return 0;
    
}