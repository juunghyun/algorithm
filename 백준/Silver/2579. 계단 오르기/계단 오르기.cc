#include <bits/stdc++.h>

using namespace std;
int N;
int dp[304];
int stairs[304];

int func(int n){

    if(n<0)return 0;
    
    if(dp[n]!=-1){
        return dp[n];
    }

    return dp[n] = max(func(n-2) + stairs[n], func(n-3) + stairs[n-1] + stairs[n]);

}

int main(){
    cin>>N;

    for(int i = 0; i<N; i++){
        cin>>stairs[i];
    }

    memset(dp, -1, sizeof(dp));

    dp[0] = stairs[0];

    cout<<func(N-1);

}