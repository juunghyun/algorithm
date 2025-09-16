#include <bits/stdc++.h>

using namespace std;

int N, T;
int timeArr[101];
int scoreArr[101];
int dp[101][10001];

int func(int idx, int time){
    if(idx < 0 || time == 0) return 0;

    if(dp[idx][time] != -1) return dp[idx][time];

    if(time - timeArr[idx] >= 0){
        dp[idx][time] = max(func(idx - 1, time), func(idx - 1, time - timeArr[idx]) + scoreArr[idx]);
    }else{
        dp[idx][time] = func(idx - 1, time);
    }

    return dp[idx][time];
}

int main(){
    cin>>N>>T;

    for(int i = 0; i<N; i++){
        cin>>timeArr[i]>>scoreArr[i];
    }

    memset(dp, -1, sizeof(dp));

    cout<<func(N-1, T);

    return 0;
}