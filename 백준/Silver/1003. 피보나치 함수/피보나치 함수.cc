#include<bits/stdc++.h>

using namespace std;

/**
 * 피보나치 dp, 0과 1이 호출되는 경우의 수를 출력하시오.
 * Test Case주어지고 N이 주어짐. 각 테스트 케이스마다 0, 1이 출력되는걸 한번 띄어서 출력
 */

int T, N;

int main(){

    cin>>T;
    for(int i = 0; i<T; i++){
        cin>>N;

        int dp[41][2];

        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[1][0] = 0;
        dp[1][1] = 1;

        
        for(int j = 2; j<=N; j++){
            dp[j][0] = dp[j-1][0] + dp[j-2][0];
            dp[j][1] = dp[j-1][1] + dp[j-2][1];
        }
        cout<<dp[N][0]<<" "<<dp[N][1]<<"\n";

    }



    return 0;
}