#include <bits/stdc++.h>

using namespace std;

/**
 * LDS 가장 긴 감소하는 부분 수열 구하삼요.
 * 모든 칸을 0 으로 설정, 그칸 볼때 일단 1로시작(무조건 1개는 침)
 * 
 */

int N;
int questionArr[1001];
int dp[1001];

int main(){
    cin>>N;

    for(int i = 0; i<N; i++){
        cin>>questionArr[i];
    }

    memset(dp, 0, sizeof(dp));

    for(int i = 0; i<N; i++){

        dp[i] = 1;

        for(int j = 0; j<i; j++){ //이전 항들 검사
            if(questionArr[i]<questionArr[j]){ //감소하는 경우가 있는 경우
                dp[i] = max(dp[j] + 1 , dp[i]);
            }
        }
    }

    int answer = 0;

    for(auto k : dp){
        answer = max(k, answer);
    }
    cout<<answer<<"\n";

    return 0;
}