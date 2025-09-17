#include <bits/stdc++.h>

using namespace std;

string inputs1, inputs2;
int dp[1001][1001];

//0,0에서 시작. 동일하면 둘다 ++. 동일하지않을 시, 1,0 / 0,1 두개 넘기기

int func(int left, int right){

    if(left < 0 || right < 0) return 0;

    if(dp[left][right] != -1) return dp[left][right];
    dp[left][right] = 0;
    
    if(inputs1[left] == inputs2[right]){
       dp[left][right] = func(left - 1, right - 1) + 1;
    }else{
        dp[left][right] = max(func(left - 1, right), func(left, right - 1));
    }

    return dp[left][right];
}


int main(){
    cin>>inputs1>>inputs2;
    memset(dp, -1, sizeof(dp));

    cout<<func(inputs1.length()-1,inputs2.length()-1);



    return 0;
}