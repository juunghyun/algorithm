#include <bits/stdc++.h>
using namespace std;
/**
 * 카드팩 종류 N개. 각각 1개~N개의 카드가 들어있음
 * 카드가 i개 포함된 카드팩 가격 : Pi
 * P1 P2 P3 P4가 각각 1 5 6 7 코스트인경우, 카드 4개 가지기 위해 최대 지불액 : 10 (2개짜리 2개사기)
 * N개의 카드를 구매하기 위해 지불해야하는 금액의 최대값을 구해라.
 * 반드시 N개를 만들어야함. 더 많이 받아서 버리는것 안됨.
 */

int N;
int price[10001];
int dp[10001];


int main(){
    cin>>N;

    for(int i = 1; i<=N; i++){
        cin>>price[i];
    }

    memset(dp, 0, sizeof(dp));

    for(int i = 1; i<=N; i++){
        int temp = 0;
        for(int j = 1; j<=i; j++){
            temp = max(temp, dp[i-j] + price[j]);
        }
        dp[i] = temp;
    }

    cout<<dp[N]<<"\n";
    

    return 0;
}