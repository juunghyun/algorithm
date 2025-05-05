#include <bits/stdc++.h>
using namespace std;
int N;
int w[20][20];
int dp[20][1<<16];
int ret = INT_MAX;
const int INF = 1e9;
int startPos;


int go(int pos, int visited){

    //visited가 n개의 비트가 켜져있는지 확인. 모두 방문했다면, 현재 지점에서 start지점 가중치 더하고 리턴
    if(visited == ((1<<N) - 1)){
        if(w[pos][startPos] == 0) return INF;
        return w[pos][startPos];
    }

    int & ret = dp[pos][visited];
    if(ret != -1)return ret; //이미 방문한 세계선
    ret = INF;

    for(int i = 0; i<N; i++){
        if(visited & (1<<i))continue; //이미 방문함?
        if(w[pos][i] == 0) continue; //길없음?
        ret = min(ret, w[pos][i] + go(i, visited | (1<<i)));
    }

    return ret;
}

int main(){
    cin>>N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>w[i][j];
        }
    }
    

    for(int i = 0; i<N; i++){
        memset(dp, -1, sizeof(dp));
        startPos = i;
        ret = min(go(i, 1<<i), ret);
    }

    cout<<ret<<"\n";

    return 0;
}