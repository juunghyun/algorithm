#include <bits/stdc++.h>

using namespace std;


//ACM 크래프트
//백준 1005
//건물을 짓는 순서가 안정해짐.
// 매 게임 시작 시 짓는 순서 주어짐. 각 건물은 지어지는 delay 존재.
// 각 건물을 짓기 위해서 선행 건물이 필요할 수 있음.

// 건물, 건물에 대한 선행건물, 건물을 짓는데 걸리는 delay가 주어지면 모든거 짓기 위한 최단시간 구하기

//테스트 케이스 T -> 건물의 개수 N, 건설 순서 규칙의 총 개수 K, 건물당 걸리는 시간

//1~N까지 건물에 대해 먼저 지을 건물을 

int T;
int N, K, W;


int func(int pos, const vector<int> & timeArr, const vector<vector<int>> & reqV, vector<int> & dp){

    if(dp[pos] != -1){ //계산된게 있다면 사용.
        return dp[pos];
    }

    int temp = 0;

    //pos가 지어지려면 필요한 건물들
    for(auto k : reqV[pos]){ //k건물이 필요함.
        temp = max(temp, func(k, timeArr, reqV, dp));
    }
    
    return dp[pos] = temp + timeArr[pos];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;

    for(int i = 0; i<T; i++){
        cin>>N>>K;
        vector<vector<int>> reqV(N+1); //N번 건물을 짓기 위해서 필요한 건물.
        vector<int> timeArr(N+1); //N번 건물을 짓는데 걸리는 시간.
        vector<int> dp(N+1, -1); //N번 건물을 짓는데 걸리는 시간.

        for(int j = 1; j<=N; j++){ //i번 건물 짓는 시간 넣기
            cin>>timeArr[j];
        }

        for(int j = 1; j<=K; j++){ //req가 있어야 desN을 지을 수 있음.
            int req, desN;
            cin>>req>>desN;
            reqV[desN].push_back(req);
        }

        cin>>W; // 목표 건물
        
        func(W, timeArr, reqV, dp);

        cout<<dp[W]<<"\n";


    }
    

    return 0;
}