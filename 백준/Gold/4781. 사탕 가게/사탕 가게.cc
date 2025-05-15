/*
같은 돈 시작
구매한 사탕의 칼로리가 더 큰 사람이 내기에서 이김

각 사탕은 매우 많음
모든 사탕의 가격, 칼로리가 주어짐. 어떻게 해야 가장 큰 합이 될지 구하시오
n m : 1~5000 종류 / 0.01~ 100.00 돈의 양. m은 항상 소수점 둘째자리
n개줄동안 칼로리 - 가격 주어짐 : 칼로리 : 1~5000 / 가격 : 0.01~100.00
입력의 마지막 줄 : 0 0.00이 주어짐.
*/
#include <bits/stdc++.h>
using namespace std;
int n;
int m;
double mTemp;
const int INF = 1e9;
int dp[10004]; //dp[가격] = 최대 칼로리 gogo
vector<pair<int, int>> candy;

int go(int price){
    if(price<0) return -INF;
    
    int &ret = dp[price];
    if(ret != -1) return ret;
    ret = 0;

    for(int i = 0; i<candy.size(); i++){
        ret = max(ret, candy[i].first + go(price - candy[i].second));
    }

    return ret;
}

int main(){

    while(true){
        cin>>n>>mTemp;
        if(n == 0 && mTemp == 0.00){
            break;
        }
        m = mTemp*100;
        
        vector<pair<int,int>> clearV;
        candy = clearV;

        for(int i = 0; i<n; i++){
            int c;
            double p;
            cin>>c>>p;
            p = round(p * 100);
            candy.push_back({c, (int)p});
        }
        memset(dp, -1, sizeof(dp));
        cout<<go(m)<<"\n";
    }


    return 0;
}