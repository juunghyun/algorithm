/*
떨어지는 시간 : T(1~1000)
movementCnt : W(1~30)

최대로 받을 수 있는 자두의 개수

초기상태 : 0번 자두나무 아래 있음. 나무 두개

떨어지는 나무의 번호가 1 or 2로 주어짐
*/

#include <bits/stdc++.h>
using namespace std;

int T, W, inputn;
int fruit[1004];
int dp[1004][2][34]; // 시간, 현재 위치, 남은 이동수

int go(int t, int pos, int movementCnt){

    // 시간이 끝났다면 리턴
    if(t>=T) return 0;

    // 메모이제이션
    int &ret = dp[t][pos][movementCnt];
    if(ret != -1) return ret; // 이미 계산한 세계선이면
    ret = 0;

    // 해당 위치에 과일이 있다면
    if(fruit[t] == pos) ret = 1;

    if(movementCnt<=0){
        ret = ret + go(t+1, pos, movementCnt);
    }else{
        ret = max((ret + go(t+1, pos, movementCnt)), ret + go(t+1, pos ^ 1, movementCnt-1));
    }

    return ret;
    
}

int main(){
    cin>>T>>W;

    for(int i = 0; i<T; i++){
        cin>>inputn;
        fruit[i] = inputn - 1;
    }

    memset(dp, -1, sizeof(dp));

    int ret = max(go(0,0,W), go(0,1,W-1));

    cout<<ret<<"\n";

    return 0;
}