/*

로봇 청소기, 방 상태 주어짐. 청소하는 영역의 개수를 구하시오
nxm 방, 각 칸은 벽 혹은 빈칸.
청소기 -> 바라보는 방향 존재 (동서남북)
각 칸의 좌표 (r,c) 최 서북단 좌표 0,0. 최남동단 n-1,m-1
빈칸 : 전부 청소되지 않은 상태.

작동 알고리즘
1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸 청소
2. 현재 칸의 주변 4칸 중 청소안댄 빈칸이 없음?
 - 1. 바라보는 방향 유지, 한칸 후진 후 1번으로 돌아가기
 - 2. 후진 불가능? stop
3. 주변 4칸중 청소 안된 빈칸 있음?
 - 1. 반시계 방향 90도 회전 (시계 270도 회전)
 - 2. 바라보는 방향 기준 앞쪽 칸 청소 안된 빈칸? 전진하세요
 - 3. 1번으로 돌아가기(청소하러 가기)

*/

#include <bits/stdc++.h>
using namespace std;

int N, M;
int questionMap[51][51];
int visited[51][51];
int robotY, robotX, robotD;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ret = 0;

void go(int y, int x, int d){ //로청 좌표와 방향
    if(visited[y][x]==0){ //청소 안된 경우
        visited[y][x] = 1; // 방문처리(청소)
        ret++;
    }

    bool check = false;
    for(int i = 0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny <0 || nx <0 || ny >= N || nx >= M) continue;
        if(questionMap[ny][nx] == 0 && visited[ny][nx] == 0) check = true; //주변 4칸 중 청소안된 빈칸 확인
    }

    if(!check){ //주변 4칸중 청소할 빈칸이 없는 경우
        //후진 가능하면 후진
        int ny = y + dy[(d + 2)%4];
        int nx = x + dx[(d + 2)%4];
        if(ny <0 || nx <0 || ny >= N || nx >= M) return;
        if(questionMap[ny][nx]==0){
            go(ny, nx, d);
            return;
        }else{ //후진 불가능하면
            return;
        }
    }else{ //주변에 청소할 빈칸 있는 경우
        d = (d+3)%4; //반시계 90도 회전
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(ny <0 || nx <0 || ny >= N || nx >= M) go(y, x, d);
        if(questionMap[ny][nx] == 0 && visited[ny][nx]==0){
            go(ny, nx, d); //해당 위치로 전진
            return;
        }else{
            go(y, x, d); //원래 좌표에서 회전만 함.
            return;
        }
    }

    return;
}

int main(){
    cin>>N>>M;
    cin>>robotY>>robotX>>robotD;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>questionMap[i][j];
        }
    }

    go(robotY, robotX, robotD);

    cout<<ret<<"\n";


    return 0;
}