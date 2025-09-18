#include <bits/stdc++.h>

using namespace std;

string inputs1, inputs2, inputs3;
int dp[101][101][101];

int func(int a, int b, int c){
    
    if(a<0 || b<0 || c<0) return 0;

    if(dp[a][b][c] != -1 )return dp[a][b][c]; //계산된 세계선이 있나요?


    //다같은 경우 / 두명만 같은 경우(3개) / 다 다른 경우 -> a만전진 b만전진 c만전진
    if(inputs1[a] == inputs2[b] && inputs2[b] == inputs3[c]){ //오직 lcs가길어지는 단 하나의 경우
        dp[a][b][c] = func(a-1, b-1, c-1) + 1;
    }else{
        dp[a][b][c] = max({func(a - 1, b, c), func(a, b - 1, c), func(a, b, c - 1)});
    }

    return dp[a][b][c];

}

int main(){
    cin>>inputs1>>inputs2>>inputs3;

    memset(dp, -1, sizeof(dp));

    cout<<func(inputs1.length()-1, inputs2.length()-1, inputs3.length()-1);


    return 0;
}