#include <bits/stdc++.h>
using namespace std;

/**
 * 0,0에서 (n-1,m-1)즉 우측 끝 점으로 이동하는 경우의 수를 구하세요.
 */

int N, M;//세로/가로
int questionMap[500][500];
//특정 좌표 dp 계산법 : 인접 4방향 중 가능한 경우들의 총집합.
//특정 좌표들의 dp가 리턴되는 경우 : questionMap[n-1][m-1] 도착 시 1 리턴.
int dy[4] = {-1,0,1,0}; //시계방향 12시시작.
int dx[4] = {0,1,0,-1};

int dp[500][500];

int func(int y, int x){

    if(y == N-1 && x == M-1){ //우측 끝 점 도착시
        return 1;
    }

    if(dp[y][x]!=-1) return dp[y][x];

    int count = 0;

    for(int i = 0; i<4; i++){//4방향 탐색.
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0||nx<0||ny>=N||nx>=M) continue; //지도밖으로 나가는 경우.
        if(questionMap[ny][nx]>=questionMap[y][x]) continue; //오르막길인경우

        //내리막길이고 지도 안인 경우만 남음
        count += func(ny,nx);
    }

    return dp[y][x] = count;
}


int main(){
    cin>>N>>M;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>questionMap[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout<<func(0,0);

    return 0;
}