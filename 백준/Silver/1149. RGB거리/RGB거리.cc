#include<bits/stdc++.h>
using namespace std;

int N;
/**
 * 3
 * 26 40 83
 * 49 60 57
 * 13 89 99
 */
int questionMap[1001][3];
int dp[1001][3];
int result;

int func(int n, int select){
    if(n == 0) return questionMap[0][select];

    //이미 계산된 세계선
    if(dp[n][select] != -1) return dp[n][select];

    if(select == 0){
        dp[n][select] = min(func(n-1, 1), func(n-1, 2)) + questionMap[n][0];
    }else if(select == 1){
        dp[n][select] = min(func(n-1, 0), func(n-1, 2)) + questionMap[n][1];
    }else if(select == 2){
        dp[n][select] = min(func(n-1, 0), func(n-1, 1)) + questionMap[n][2];
    }

    return dp[n][select];

}

int main(){
    cin>>N;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<3; j++){
            cin>>questionMap[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    result = min({func(N-1, 0), func(N-1, 1), func(N-1, 2)});
    cout<<result<<"\n";

    return 0;
}