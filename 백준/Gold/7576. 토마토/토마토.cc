#include <bits/stdc++.h>
using namespace std;
int N, M;
int questionMap[1004][1004];
int visited[1004][1004];
int inputn, wellDayCnt;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

vector<pair<int,int>> wellMato;

int main(){
    cin>>M>>N;
    bool alreadyFin = true;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>inputn;
            questionMap[i][j] = inputn;
            if(inputn == 1){
                wellMato.push_back({i,j}); //익은 토마토 벡터
            }else if(inputn == 0){
                alreadyFin = false; //익을 토마토 존재
            }
        }
    }

    //이미 다 익은 토마토만 있나요?
    if(alreadyFin){
        cout<<0<<"\n";
        return 0; //프로그램 종료
    }


    queue<pair<int,int>>q;
    for(auto k : wellMato){
        visited[k.first][k.second] = 1;
        q.push(k);
    }

    while(!q.empty()){
        int qSize = q.size(); //일수별 익은 토마토 개수
        vector<pair<int, int>> tomatoV;
        for(int l = 0; l<qSize; l++){
            pair<int, int> wellMatoPiece;
            wellMatoPiece = q.front();
            q.pop();
            visited[wellMatoPiece.first][wellMatoPiece.second] = 1;
            for(int i = 0; i<4; i++){
                int ny = dy[i] + wellMatoPiece.first;
                int nx = dx[i] + wellMatoPiece.second;
                if(ny<0 || nx<0 || ny>=N || nx>=M || visited[ny][nx]) continue; //맵 밖을 넘어가거나, 방문했거나, 안익은 토마토 칸이 아니라면
                //안익은 토마토 칸이라면
                if(questionMap[ny][nx]==0){
                    tomatoV.push_back({ny,nx});
                    q.push({ny,nx});
                    visited[ny][nx] = 1;
                }else if(questionMap[ny][nx]==-1){ //아무것도 없는 칸이라면
                visited[ny][nx] = 1; //방문처리해서 다시 안가게끔 하기.
                }
                
            }
        }
        for(auto k : tomatoV){
            questionMap[k.first][k.second] = 1;
            visited[k.first][k.second] = 1;
        }
        tomatoV.clear();
        wellDayCnt++;

    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(questionMap[i][j] == 0){
                //못 익은 토마토 존재
                cout<<-1<<"\n";
                return 0; //프로그램 종료
            }
        }
    }

    cout<<wellDayCnt-1<<'\n';



    return 0;
}