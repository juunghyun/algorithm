#include<bits/stdc++.h>
using namespace std;
int N,M,H, inputn;
int dy[6] = {-1,0,1,0,0,0};
int dx[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int questionMap[104][104][104];
int visited[104][104][104];
queue<tuple<int, int, int>> tomatoQ;
int ret = 0;

int main(){
    cin>>M>>N>>H;

    bool wellMato = false;
    bool notWellMato = false;
    for(int z = 0; z<H; z++){
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                cin >> inputn;
                questionMap[i][j][z] = inputn;
                if(inputn == 0){
                    notWellMato = true;
                }else if(inputn == 1){
                    tomatoQ.push({i,j,z});
                    wellMato = true;
                }
            }
        }
    }



    if(!notWellMato && wellMato){ //안익은 토마토 없고 익은 토마토만 있으면
        cout<<0<<"\n";
        return 0;
    }

    if(!wellMato && notWellMato){ //익은 토마토 없고 안익은 토마토만 있음
        cout<<-1<<"\n";
        return 0;
    }

    while(!tomatoQ.empty()){

        ret++;
        int qSize = tomatoQ.size();

        for(int i = 0; i<qSize; i++){

            int y, x, z;
            tie(y,x,z) = tomatoQ.front();
            tomatoQ.pop();
            visited[y][x][z] = 1;

            for(int i = 0; i<6; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                int nz = z + dz[i];
                if(ny<0 || nx<0 || nz<0 || ny>=N || nx>=M || nz>=H || visited[ny][nx][nz] || questionMap[ny][nx][nz] != 0) continue; //방문했거나 맵 넘어가면 안감
                if(questionMap[ny][nx][nz]==0){ //안 익은 토마토 칸이면
                    visited[ny][nx][nz]=1; //해당 칸 방문처리하고
                    questionMap[ny][nx][nz] = 1; //토마토 익게 만들기.
                    tomatoQ.push({ny,nx,nz}); //다음 처리할 토마토 벡터에 넣어놓기.
                }
            }
        }

    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            for(int z = 0; z<H; z++){
                if(questionMap[i][j][z] == 0){
                    cout<<-1<<"\n";
                    return 0;
                }
            }
        }
    }


    cout<<ret-1<<'\n';

    return 0;
}