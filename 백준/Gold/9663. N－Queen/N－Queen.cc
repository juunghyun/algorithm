/*
n queen

N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

1. 첫번째 퀸 놓기
2. 두번째 퀸 놓기 - 해제... N개까지 놓기
*/

#include <bits/stdc++.h>
using namespace std;
int N;
int col[16]; //열
int diag1[32]; //좌측 상단에서 우측 하단 방향 대각선
int diag2[32]; //우측 상단에서 좌측 하단 방향 대각선
int ret = 0;


void go(int row){

    if(row == N){
        ret++;
        return;
    }

    for(int i = 0; i<N; i++){//col
        if(col[i]!=1 && diag1[i - row + N - 1]!=1 && diag2[row + i] != 1){ //열, 대각선 모두 안걸리는 곳이라면
            col[i] = 1;
            diag1[i-row+N-1] = 1;
            diag2[row + i] = 1;
            go(row + 1);
            col[i] = 0;
            diag1[i-row+N-1] = 0;
            diag2[row + i] = 0;
        }
    }

    return;
}

int main(){
    cin>>N;
    go(0);

    cout<<ret<<"\n";


    return 0;
}