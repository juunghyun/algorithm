#include <bits/stdc++.h>
using namespace std;

/**
 * 오르막 수
 * 수의 자리가 오름차순을 이루는 수를 말함
 * 인접한 수가 동일해도 오름차순으로 침
 * 2234 : 오르막수
 * 9111 : 오르막수 아님
 * 오르막수의 개수를 구하는 프로그램.
 * 길이를 줄테니 오르막수의 개수를 구하거라.
 */
/**
 * dp[1][0]~dp[1][9] = 다 1.
 * -> dp[1][1] 인 경우 dp[2][0] dp[2][1]에 ++ 한다.
 * 즉 dp[N][k]인 수는 dp[N-1][k이하]인 모든걸 더하면됨
 */
int N; //길이가 N인 오르막수의 개수를 구하셈.
int res = 0;
int dp[1001][10];

int main(){
    cin>>N;

    memset(dp, 0, sizeof(dp));

    for(int i = 0; i<10; i++){
        dp[1][i] = 1;
    }

    for(int i = 2; i <= N; i++){
        for(int j = 0; j<10; j++){
            for(int z = 0; z<=j; z++){
                dp[i][j] = (dp[i][j] + dp[i-1][z]) % 10007;
            }
        }
    }

    for(int i = 0; i<10; i++){
        res = (res + dp[N][i]) % 10007;
    }

    cout<<res%10007;

    return 0;
}