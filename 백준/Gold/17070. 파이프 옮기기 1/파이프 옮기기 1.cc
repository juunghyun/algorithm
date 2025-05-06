#include <bits/stdc++.h>
using namespace std;
int N;
int questionMap[20][20];
int dy[3] = {0,1,1};
int dx[3] = {1,1,0};
//우측, 대각선, 하단 / 0, 1, 2 순서
int dp[20][20][3];

int go(int y, int x, int dir){ //dir 0 : 우측 / 1 : 좌하단 / 2 : 하단
    //종료조건
    if(y == N-1 && x == N-1){
        return 1;
    }

    int &ret = dp[y][x][dir];
    if(ret != -1) return ret;
    ret = 0;

    for(int i = 0; i<3; i++){
        if(dir == 0 && i == 2) continue;
        if(dir == 2 && i == 0) continue;
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny>=N || nx>=N || questionMap[ny][nx] == 1) continue; // 지도밖 or 벽 못감
        if(i == 1){
            if(questionMap[y+1][x] == 1 || questionMap[y][x+1] ==1) continue;
        }
        ret += go(ny, nx, i);
    }

    return ret;
}

int main(){

    cin>>N;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>questionMap[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout<<go(0, 1, 0)<<'\n';


    return 0;
}