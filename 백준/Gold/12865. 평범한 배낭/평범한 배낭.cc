#include <bits/stdc++.h>

using namespace std;

/**
 * 준서가 여행에 필요하다고 생각하는 N개의 물건이 있다. 각 물건은 무게 W와 가치 V를 가지는데, 
 * 해당 물건을 배낭에 넣어서 가면 준서가 V만큼 즐길 수 있다. 
 * 아직 행군을 해본 적이 없는 준서는 최대 K만큼의 무게만을 넣을 수 있는 배낭만 들고 다닐 수 있다. 
 * 준서가 최대한 즐거운 여행을 하기 위해 배낭에 넣을 수 있는 물건들의 가치의 최댓값을 알려주자.
 * 입력
 * 첫 줄에 물품의 수 N(1 ≤ N ≤ 100)과 준서가 버틸 수 있는 무게 K(1 ≤ K ≤ 100,000)가 주어진다.
 * 두 번째 줄부터 N개의 줄에 거쳐 각 물건의 무게 W(1 ≤ W ≤ 100,000)와 
 * 해당 물건의 가치 V(0 ≤ V ≤ 1,000)가 주어진다.
 * 입력으로 주어지는 모든 수는 정수이다.
 * 4 7
 * 6 13
 * 4 8
 * 3 6
 * 5 12
 */
int N, K;
int dp[101][100001];
int myweight[101];
int value[101];

int func(int idx, int w){
    if(idx < 0 || w == 0) return 0;

    if(dp[idx][w] != -1) return dp[idx][w]; //계산된 세계선이 있다면..

    if(w - myweight[idx] >= 0){
        dp[idx][w] = max(func(idx-1, w), func(idx-1, w - myweight[idx]) + value[idx]);
    }else{
        dp[idx][w] = func(idx-1, w);
    }

    return dp[idx][w];
}

int main(){

    cin>>N>>K;

    for(int i = 0; i<N; i++){
        cin>>myweight[i]>>value[i];
    }

    memset(dp, -1, sizeof(dp));

    cout<<func(N-1, K);



    return 0;
}