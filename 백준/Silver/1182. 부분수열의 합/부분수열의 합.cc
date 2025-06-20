/*
N개의 정수
크기가 양수인 부분수열 중 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수 구하기
*/

#include <bits/stdc++.h>
using namespace std;

int N, S;
int arr[21];
int ret = 0;

void go(int index, int sum){

    if(index == N){
        if(sum == S){
            ret ++;
        }       
        return;
    }
    
    //선택하기
    go(index + 1, sum + arr[index]);

    //선택 안하기
    go(index + 1, sum);

    return;
}



int main(){
    cin>>N>>S;

    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }

    go(0, 0);
    if(S==0){
        ret--;
    }

    cout<<ret<<"\n";

    return 0;
}