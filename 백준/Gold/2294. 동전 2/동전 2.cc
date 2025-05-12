/*
n종류 동전 1~100
가치합 : k 1~10000
동전의 개수 최소. 구하셈!
각 동전의 가치 : 1~100000
가치같은 동전 여러갤수도?
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, k, inputn;
set<int> coin;
int dp[10004];

int go(int sum){
    if(sum == 0){
        return 0;
    }

    if(sum < 0){
        return INF;
    }

    int &ret = dp[sum];
    if(ret != -1) return ret;
    ret = INF;

    for(auto k : coin){
        ret = min(ret, 1 + go(sum-k));
    }

    return ret;

}

int main(){
    cin>>n>>k;

    for(int i = 0; i<n; i++){
        cin>>inputn;
        coin.insert(inputn);
    }

    memset(dp, -1, sizeof(dp));
    if(go(k)>100000){
        cout<<-1<<"\n";
    }else{
        cout<<go(k)<<"\n";
    }

    return 0;
}