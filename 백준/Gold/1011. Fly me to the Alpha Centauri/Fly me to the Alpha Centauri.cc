#include <bits/stdc++.h>

using namespace std;

int T;


int main(){
    cin>>T;

    for(int i = 0; i<T; i++){
        int x, y;
        cin>>x>>y;
        
        int ret = 0;

        int n = sqrt(y - x);
        int minusNum = (y - x) - pow(n, 2);
        
        ret += 2*n - 1;

        ret += minusNum / n;

        if(minusNum%n !=0){
            ret += 1;
        }
        
        cout<<ret<<"\n";

    }

    return 0;
}