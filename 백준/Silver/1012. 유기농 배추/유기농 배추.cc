#include <bits/stdc++.h>
using namespace std;
int T, N, M, K;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int y, x;
int visited[51][51];
int questionArr[51][51];
int ret = 0;

void dfs(int y, int x){
    visited[y][x] = 1; //방문처리

    for(int i = 0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || nx<0 || ny>=N || nx>=M || visited[ny][nx] || questionArr[ny][nx]==0) continue; //맵 밖이거나, 방문했거나, 0이면 가지마셈
        dfs(ny, nx); //아니면 가세욤
    }

    return;
}

int main(){
    cin>>T;
    for(int i = 0; i<T; i++){
        cin>>M>>N>>K;
        memset(visited, 0, sizeof(visited));
        memset(questionArr, 0, sizeof(questionArr));
        ret = 0;
        int inputX, inputY;
        for(int j = 0; j<K; j++){
            cin>>inputX>>inputY;
            questionArr[inputY][inputX] = 1;
        }

        for(int j = 0; j<N; j++){
            for(int z = 0; z<M; z++){
                if(questionArr[j][z]==1 && visited[j][z]==0){ //1이고 방문도 안했으면 ㄱㄱ
                    dfs(j, z);
                    ret++;
                }
            }
        }
        cout<<ret<<"\n";

    }

    return 0;
}