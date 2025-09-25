#include <bits/stdc++.h>
using namespace std;

/**
 * 
 * 0 ~ N까지 정수 K개를 더해 그 합이 N이 되는 경우의 수를 구하라.
 * 덧셈의 순서가 바뀐 경우 다른 경우로 침.
 * 한개의 수 중복 사용도 가능.
 * N : 200이하 정수
 * K : 200이하 정수
 * ex) 20,2일 경우 2개의 수로 20의 합을 만들어야함. 0~20까지의 정수여야함.
 * 0+20 ~ 20 + 0 까지 총 21개임.
 * dp[현재 합][사용한 수 개수] 이렇게 해야하나? 일단 어떤 수를 사용했냐는 딱히 중요하지않음. 어차피 중복 가능.
 */

int N, K;
const int fixedNum = 1000000000;
long long dp[201][201];

long long func(int curNum, int idx){
    if(idx == 1 && curNum>=0) return 1;

    if(dp[curNum][idx] != -1)return dp[curNum][idx];

    long long count = 0;

    for(int i = 0; i<=N; i++){
        if(curNum - i >= 0){
            count = (count + func(curNum-i, idx-1))%fixedNum;
        }
    }

    

    return dp[curNum][idx] = count;
}

int main(){
    cin>>N>>K;

    memset(dp, -1, sizeof(dp));

    cout<<func(N, K)%fixedNum;

    return 0;
}