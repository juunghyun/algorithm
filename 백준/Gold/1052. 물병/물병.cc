#include <bits/stdc++.h>
using namespace std;

int ret = 0;
int N, K, firstN;

int main(){
    cin>>firstN>>K;
    N = firstN;

    // 1. 현재 2진수 켜진 비트 자릿 수 세기
    // 2. K개 이하라면 끝
    // 3. K개 초과라면 가장 낮은 자릿수 켜진비트 더하기 -> 1번으로.
    int cnt = 1e9;
    while(true){
        cnt = __builtin_popcount(N); //켜진 비트 수

        if(cnt<=K){
            ret = N - firstN;
            break;
        }else{
            int temp = (N & -N);
            N += temp;
        }
    }
    

    cout<<ret<<"\n";



    return 0;
}