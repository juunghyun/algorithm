#include<bits/stdc++.h>
using namespace std;

int N, M;
int questionMap[104][104];
int visited[104][104];
int cheese[104][104];
int ret = 0;
vector<pair<int, int>> cheeseV;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

/**
 * 0,0 부터 dfs로 탐색하면 전체 바깥공기 탐색 가능. visited 하면서 가기.
 * 바깥공기에서 치즈 만나면 해당 cheese ++
 * 끝나고 cheese 2이상인 칸 questionMap갱신 밑 visited, cheese 초기화.
 */

void dfs(int y, int x){
    visited[y][x] = 1;

    for(int i = 0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] == 1) continue;
        if(questionMap[ny][nx] == 1){
            cheese[ny][nx]++;
        }else{
            dfs(ny, nx);
        }
    }

    return;
}

int calculCheese(){
    int myCount = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(questionMap[i][j]==1)myCount++;
        }
    }
    return myCount;
}

int main(){
    cin>>N>>M;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>questionMap[i][j];
        }
    }

    while(calculCheese() != 0){
        //dfs탐색
        dfs(0,0);

        ret++;

        //cheese2이상 부분 questionMap갱신
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                if(cheese[i][j] > 1){
                    questionMap[i][j] = 0;
                }
            }
        }


        //visited, cheese 초기화
        memset(visited, 0, sizeof(visited));
        memset(cheese, 0, sizeof(cheese));

    }

    cout<<ret<<"\n";


    return 0;
}