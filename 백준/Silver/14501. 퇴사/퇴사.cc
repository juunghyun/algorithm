#include <bits/stdc++.h>
using namespace std;

int N;
int timeArr[16];
int pay[16];
int dp[16];

int main(){
    cin>>N;

    for(int i = 1; i<=N; i++){
        cin>>timeArr[i]>>pay[i];
    }

    memset(dp, 0, sizeof(dp));
    
    for(int i = 1; i<=N; i++){
        //상담 x
        dp[i] = max(dp[i], dp[i-1]);

        //상담 o
        int endDay = i + timeArr[i];
        //상담 가능하다면 ㄱㄱ
        if(endDay <= N + 1){
            dp[endDay] = max(dp[i]+pay[i], dp[endDay]);
        }

    }
    cout<<max(dp[N], dp[N+1])<<"\n";


    
    return 0;
}