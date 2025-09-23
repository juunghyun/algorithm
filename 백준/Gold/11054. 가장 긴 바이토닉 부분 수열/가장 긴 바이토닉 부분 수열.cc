#include <bits/stdc++.h>
using namespace std;
int N;
int numArr[1001];
int dp[1001]; //오름차순 
int dp2[1001]; //내림차순
int res = 0;

int main(){
    cin>>N;

    for(int i = 1; i<=N; i++){
        cin>>numArr[i];
    }

    memset(dp, 0, sizeof(dp));
    memset(dp2, 0, sizeof(dp2));

    for(int i = 1; i<=N; i++){
        dp[i] = 1;
        for(int j = 1; j<i; j++){
            if(numArr[i]>numArr[j]) dp[i] = max(dp[i], dp[j]+1);
        }
    }

    for(int i = N; i>=1; i--){
        dp2[i] = 1;
        for(int j = N; j>i; j--){
            if(numArr[i]>numArr[j]) dp2[i] = max(dp2[i], dp2[j]+1);
        }
    }

    for(int i = 1; i<=N; i++){
        res = max(res, dp[i] + dp2[i]);
    }

    cout<<res-1<<"\n";


    return 0;
}