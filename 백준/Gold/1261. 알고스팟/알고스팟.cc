#include<bits/stdc++.h>

using namespace std;
int M, N;
const int INF = 1e9;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main(){
    cin>>M>>N;

    vector<vector<int>> questionMap(N, vector<int>(M));
    vector<vector<int>> dist(N, vector<int>(M, INF));

    for(int i = 0; i<N; i++){
        string inputs;
        cin>>inputs;
        for(int j = 0; j<M; j++){
            questionMap[i][j] = inputs[j] - '0';
        }
    }

    deque<pair<int, int>> dq;
    dq.push_front({0,0});
    dist[0][0] = 0;

    while(!dq.empty()){
        pair<int, int> tempPos = dq.front();
        dq.pop_front();
        int y = tempPos.first;
        int x = tempPos.second;

        for(int i = 0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=M) continue; //벽에 막혔으면 컨티뉴
            int cost = dist[y][x] + questionMap[ny][nx];

            if(dist[ny][nx]>cost){
                dist[ny][nx]=cost;
                if(questionMap[ny][nx]==1){
                    dq.push_back({ny,nx});
                }else{
                    dq.push_front({ny,nx});
                }
            }

        }
    }

    cout<<dist[N-1][M-1];

    return 0;
}