#include <bits/stdc++.h>
using namespace std;
int N, M;
int questionMap[1025][1025];
int prefixSum[1025][1025];


int main(){

    ios::sync_with_stdio(false);
	cin.tie(0);

    cin>>N>>M;

    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            cin>>questionMap[i][j];
        }
    }
    memset(prefixSum, 0, sizeof(prefixSum));

    
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            prefixSum[i][j] = questionMap[i][j] 
            + prefixSum[i-1][j]
            + prefixSum[i][j-1]
            - prefixSum[i-1][j-1];
        }
    }

    for(int i = 0; i<M; i++){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        long long result = prefixSum[y2][x2]
                          - prefixSum[y1 - 1][x2]
                          - prefixSum[y2][x1 - 1]
                          + prefixSum[y1 - 1][x1 - 1];
        cout<<result<<"\n";

    }
    

    return 0;
}