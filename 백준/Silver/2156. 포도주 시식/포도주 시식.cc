#include <bits/stdc++.h>

using namespace std;

int N;
int value[10001];
int dp[10001];

int main(){
    cin>>N;
    for(int i = 1; i<=N; i++){
        cin>>value[i];
    }

    memset(dp, 0, sizeof(dp));

    dp[1] = value[1];

    if(N>=2){
        dp[2] = value[1] + value[2];
    }

    for(int i = 3; i<=N; i++){
        dp[i] = max({dp[i-1], 
            dp[i-2] + value[i],
            dp[i-3] + value[i] + value[i-1]
        });
    }

    cout<<dp[N]<<"\n";



    return 0;
}