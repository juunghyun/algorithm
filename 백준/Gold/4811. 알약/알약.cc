/*
약 개수 : N
하루마다 약 1개 꺼내고 반으로 쪼개 하난 먹고 하난 다시 병에 넣음.
담날 약 1개 꺼냄(쪼개진거든 뭐든 들어있는거 아무거나)
반조각이면 먹고 아니면 쪼개서 넣기
1조각 꺼낸날 W, 반조각 꺼낸 날 H
2N일이 지나면 길이가 2N문자열 생김.
이때 가능한 문자열의 개수
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int inputn;
vector<int> testCase;
ll dp[31][31]; // 온전한 조각 / 반쪽짜리 조각

ll go(int fullP, int halfP, int cnt){
    if(cnt<= 0) return 1; // 2N 시간 끝

    ll &ret = dp[fullP][halfP];
    if(ret != -1) return ret;
    ret = 0;

    if(halfP > 0){
        if(fullP > 0){
            ret += go(fullP - 1, halfP + 1, cnt - 1) + go(fullP, halfP - 1, cnt - 1);
        }else{
            ret += go(fullP, halfP - 1, cnt - 1);
        }
    }else{
        ret += go(fullP - 1, halfP + 1, cnt - 1);
    }

    return ret;
}


int main(){
    while(true){
        cin>>inputn;
        if(inputn == 0) break;

        testCase.push_back(inputn);
    }

    for(auto k : testCase){
        memset(dp, -1, sizeof(dp));
        cout<<go(k, 0, 2*k)<<'\n';
    }
    

    return 0;
}