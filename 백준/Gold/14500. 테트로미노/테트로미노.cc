#include <bits/stdc++.h>
using namespace std;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int quesitonMap[504][504];
int visited[504][504];
int N, M;
int ret = INT_MIN;

void clearVisitedArr(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            visited[i][j] = 0;
        }
    }
}

void dfs(int y, int x, int sum, int depth){

    sum += quesitonMap[y][x];
    visited[y][x] = 1;

    if(depth == 3){
        ret = max(ret, sum);
        visited[y][x]=0;
        return;
    }
    
    for(int i = 0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || nx<0 || ny>=N || nx>=M || visited[ny][nx]) continue;
        dfs(ny, nx, sum, depth + 1);
    }
    visited[y][x] = 0;
}

void T(int y, int x){ //{y, x}는 중심점
    for(int i = 0; i<4; i++){ //상 하 좌 우 중 안갈곳 선택
        int sum  = quesitonMap[y][x]; //중심점 좌표 일단 넣기

        for(int j = 0; j<4; j++){ //3방향 돌리기
            if(j == i) continue; //상 하 좌 우 중 안갈곳 선택
            int ny = y + dy[j];
            int nx = x + dx[j];
            if(ny>= 0 && nx >= 0 && ny < N && nx < M) sum += quesitonMap[ny][nx];//올바른 범위 안이면
        }
        ret = max(ret, sum);
    }
    return;
}

int main(){
    cin>>N>>M;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin>>quesitonMap[i][j];
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            dfs(i,j,0,0); //i, j, sum, depth
            T(i,j);
        }
    }

    cout<<ret<<"\n";
    
    return 0;
}