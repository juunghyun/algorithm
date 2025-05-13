/*
n종류 동전 1~100
가치합 : k 1~10000
K가 합이 대는 경우의수는? 같은 조합일 시 같은 경우로 침.
각 동전의 가치 : 1~100000
가치같은 동전 여러갤수도?
*/
#include <bits/stdc++.h>
using namespace std;

int n, k, inputn;
set<int> coinTemp;
int coinSize = 0;
int coin[104];
int dp[10004];

int main(){
    cin>>n>>k;

    for(int i = 0; i<n; i++){
        cin>>inputn;
        coinTemp.insert(inputn);
    }

    for(auto k : coinTemp){
        coin[coinSize++] = k;
    }

    dp[0] = 1;

    for(int i = 0; i<coinSize; i++){
        for(int j = coin[i]; j<=k; j++){
            dp[j] += dp[j - coin[i]];
        }
    }

    cout<<dp[k]<<"\n";


    return 0;
}