#include <bits/stdc++.h>
using namespace std;
int N;
int questionArr[101][101];
int visited[101][101];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int y, x;
int ret = -987654321;
map<int, int> mp;

void dfs(int y, int x, int height){
    visited[y][x] = 1;//방문처리
    for(int i = 0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0||nx<0||ny>=N||nx>=N||visited[ny][nx]||questionArr[ny][nx]-height<=0)continue; //맵 밖이거나 방문했거나 물에 잠겼으면 가지마셈
        dfs(ny, nx, height);
    }

    return;
}

void check(int height){ //물 높이가 height일 때 컴포넌트의 개수를 찾는 함수
    int ccCount = 0;
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(visited[i][j]==0 && questionArr[i][j]-height>0){ //방문한적 없고 안잠긴곳이면
            dfs(i,j, height); //해당 좌표 dfs돌려
            ccCount++;
            }
        }
    }
    ret = max(ccCount, ret);

}

int main(){
    cin>>N;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>questionArr[i][j];
            if(mp[questionArr[i][j]]==0){ //없던거임?
                mp[questionArr[i][j]] = 1; //추가욧
            }
        }
    }

    for(auto k : mp){
        if(k.second!=0){
            check(k.first);
        }
    }
    if(ret<=0){
        cout<<1<<'\n';
    }else{
        cout<<ret<<"\n";
    }

    return 0;
}