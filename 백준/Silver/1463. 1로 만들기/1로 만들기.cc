/*
1. 정수 x가 3으로 나눠떨어지면 3으로 나눠
2. x가 2로 나눠떨어지면 2로 나눠
3. 1을 빼

이렇게 3개 연산 가능.
적절히 사용해서 1을 만들려고 함.
연산을 사용하는 횟수의 최솟값 출력 ㄱㄱ
*/

#include <bits/stdc++.h>
using namespace std;

int N; //1~백만
int dp[1000006];
const int INF = 1e9;


int func(int n){
    if(n == 1)return 0;
    if(n<1)return INF;

    int &ret = dp[n];
    if(ret!=-1)return ret;
    ret = INF;

    if(n%3 == 0){
        ret = min(ret, 1 + func(n / 3));
    }

    if(n%2 == 0){
        ret = min(ret, 1 + func(n/2));
    }

    ret = min(ret, 1 + func(n-1));

    return ret;

}

int main(){
    cin>>N;
    memset(dp, -1, sizeof(dp));

    cout<<func(N)<<"\n";

    return 0;
}