#include <bits/stdc++.h>

//호텔의 고객을 C명 늘리기 위해 투자해야하는 돈의 최솟값
//C N이 주어짐 / C : 1000 이하 자연수, N : 20 이하 자연수
//C : 목표치 , N : 도시의 개수
//어떤 도시에 9원 들여 홍보하면 3명 고객 늘어남! 이런 비용이 있음.
//이러면 정수배 투자 가능.

using namespace std;

int C, N;

int func(int cnt, vector<int> & dp, vector<pair<int, int>> & cityV){

    if(cnt<=0){
        return 0;
    }

    if(dp[cnt]!=-1)return dp[cnt];

    int temp = 1e9;

    for(int i = 0; i<N; i++){
        int reqPrice = cityV[i].first; //필요한 가격
        int upCnt = cityV[i].second; //올라가는 수치

        temp = min(temp, reqPrice + func(cnt - upCnt, dp, cityV));
    }

    return dp[cnt] = temp;
}

int main(){

    cin>>C>>N;

    vector<pair<int, int>> cityV(N); //도시 인덱스에 
    vector<int> dp(C+1, -1);

    for(int i = 0; i<N; i++){
        int reqPrice;
        int upCnt;
        cin>>reqPrice>>upCnt;
        cityV[i] = {reqPrice, upCnt};
    }

    cout<<func(C, dp, cityV);


    return 0;
}