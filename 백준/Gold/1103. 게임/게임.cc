#include<bits/stdc++.h>
using namespace std;
int N, M;
string inputs;
int questionMap[51][51];
int visited[51][51];
int dp[51][51];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool isCycle = false;


int go(int y, int x){

    // 종료조건 1 - 벽 밖 or 구멍
    if(y<0 || x<0 || y>=N || x>=M || questionMap[y][x] == -1){
        return 0;
    }

    // 종료조건 2 - 중복 방문(무한루프)
    if(visited[y][x]) {
        isCycle = true;
        return 0;
    }

    // 메모이제이션
    int &ret = dp[y][x];
    if(ret != -1) return ret;
    ret = 0;

    // 방문처리
    visited[y][x] = 1;

    int mapNum = questionMap[y][x];
    for(int i = 0; i<4; i++){
        int ny = dy[i]*mapNum + y;
        int nx = dx[i]*mapNum + x;
        ret = max(ret, 1 + go(ny,nx));
    }

    // 원상복구
    visited[y][x] = 0;

    return ret;
}

int main(){
    cin>>N>>M;

    for(int i = 0; i<N; i++){
        cin>>inputs;
        for(int j = 0; j<M; j++){
            if(inputs[j]=='H'){
                questionMap[i][j] = -1;
            }else{
                questionMap[i][j] = inputs[j] - '0';
            }
        }
    }

    memset(dp, -1, sizeof(dp));

    int ret = go(0,0);
    if(isCycle){
        cout<<-1<<"\n";
    }else{
        cout<<ret<<"\n";
    }

    return 0;
}