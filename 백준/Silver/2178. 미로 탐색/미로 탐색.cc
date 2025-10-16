#include  <bits/stdc++.h>

using namespace std;

int n, m;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

//1 based인데 0based로풀거임, 우측 핟단으로 이동할 때 지나야 하는 최소의 칸 수 구하기. -> bfs
//최대크기 100,100, 0 : 벽 / 1 : 길

int main(){

    vector<vector<int>> questionMap(100, vector<int>(100)); //100 100 2차원 배열
    vector<vector<int>> visited(100, vector<int>(100, 0));
    cin>>n>>m;

    //지도넣기
    for(int i = 0; i<n; i++){
        string inputs;
        cin>>inputs;
        for(int j = 0; j<m ; j++){
            questionMap[i][j] = inputs[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    q.push({0,0});
    visited[0][0] = 1;

    while(!q.empty()){
        pair<int, int> p = q.front();
        int y = p.first;
        int x = p.second;
        q.pop();

        for(int i  = 0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || nx<0 || ny>= n || nx>= m || visited[ny][nx] || questionMap[ny][nx] == 0){ //맵 밖이거나 벽이거나 방문한곳이면
                continue;
            }
            //맵 안이고 갈수있는곳이라면,
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1; //거리는 + 1
        }
    }

    cout<<visited[n-1][m-1];

    return 0;
}