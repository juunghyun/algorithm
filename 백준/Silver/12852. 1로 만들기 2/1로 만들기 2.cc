/*
정수 x에 사용 가능한 연산
1. 3으로 나뉘면 3으로 나누기
2. 2로 나뉘면 2로 나누기
3. 1 빼기

위 1~3 연산을 적절히사용해서 1 만들거임. 
연산 최소값 구해!
N주어질거임. 1~백만 자연수
*/
#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1000004];
int from[1000004];
const int INF = 1e9;

int go(int n){
    if(n == 0){
        return 0;
    }

    int &ret = dp[n];
    if(ret != -1) return ret;
    ret = INF;

    if(n%2 == 0){
        if(ret > 1 + go(n/2)){
            ret = 1 + go(n/2);
            from[n] = n/2;
        }
    }

    if(n%3 ==0){
        if(ret > 1 + go(n/3)){
            ret = 1 + go(n/3);
            from[n] = n/3;
        }
    }

    if(ret > 1 + go(n-1)){
        ret = 1 + go(n-1);
        from[n] = n - 1;
    }

    return ret;
}

int main(){

    cin>>N;
    memset(dp, -1, sizeof(dp));

    dp[1] = 0;

    cout<<go(N)<<"\n";

    cout<<N<<" ";
    for(int i = N; i!=1; i = from[i]){
        cout<<from[i]<<" ";
    }


    return 0;
}