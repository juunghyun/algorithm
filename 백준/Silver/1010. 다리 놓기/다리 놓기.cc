#include <bits/stdc++.h>

using namespace std;

/**
 * 다리 놓기
 * 강 서쪽엔 N개 사이트 / 동쪽엔 M개의 사이트. (N<=M)
 * 이 사이트끼리 다리 연결 ㄱ
 * 서쪽의 사이트 전체를 다 연결할거임.
 * 다리가 겹쳐질 수 없음. 그럼 다리 지을 수 있는 경우의 수를 구하거라..
 * 겹쳐질 수 없다 = "조합"
 * 그냥 mCn을 구하는거긴함. -> 동쪽의 M을 기준으로 dp돌리는데 필요한거 현재 선택한 개수.
 * 기저조건 : 선택한 개수가 n개면 종료. 혹은 동쪽 인덱스가 0으로 가면 끝.
 */

int dp[31][31]; //idx / selected 
int n, m;

int func(int idx, int selected){
    if(selected == n){
        return 1; //1가지 경우
    }

    if(idx == 0){
        return 0; //다했는데 selected안걸렸으면 의미없음
    }

    if(dp[idx][selected]!= -1)return dp[idx][selected];

    int count = 0;
    count = func(idx-1, selected + 1) + func(idx - 1, selected);

    return dp[idx][selected] = count;
}

int main(){
    int T;
    cin>>T;

    for(int i = 0; i<T; i++){
        cin>>n>>m;
        memset(dp, -1, sizeof(dp));
        cout<<func(m, 0)<<"\n";
    }

    

    return 0;
}