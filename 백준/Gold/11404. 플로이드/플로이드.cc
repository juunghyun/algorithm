#include <bits/stdc++.h>

int n; //2~100 도시 개수
int m; //1~10만 버스 개수 (한 도시에서 다른 도시에 도착하는 버스)

//(A,B) 도시의 쌍에 대해서, A->B로 가는 비용의 최소값을 구하삼.
//버스 입력값 : 출발 도시, 도착 도시, 비용 즉 이건 단방향임.
//노선은, 하나가 아닐 수 잇음. 즉 노선 완성해도 그게 최소값이라는 보장 없음

using namespace std;

int main(){
    cin>>n>>m;
    vector<pair<int, int>> bus[n+1]; //각 버스가 갈 수 잇는 곳, 비용
    //1~n까지 시작도시를 idx로. 안에 들어있는 pair는 도착도시 및 비용


    //간선 정보 다 받기.
    for(int i = 0; i<m; i++){
        int startPos, endPos, cost;
        cin>>startPos>>endPos>>cost;
        bus[startPos].push_back({endPos, cost});
    }

    //[a][b] 면, a->b로 가는 최소 비용.
    vector<vector<int>> questionMap(n+1, vector<int>(n+1, 1e9)); //모두 다 1e12로 채우기.

    //간선들을 통해서 여러개 안거치고, 딱 1개만 거쳐갈 수 있는 최소값
    //모든 시작 도시들에 대해서
    for(int i = 1; i<=n; i++){
        if(!bus[i].empty()){ //해당 도시에서 출발하는 버스가 있어?
            for(auto k : bus[i]){ // i-> k.first로 가는 버스의 비용은 k.second
                questionMap[i][k.first] = min(questionMap[i][k.first], k.second); //원래 비용이랑 지금 비용
            }
        }
    }

    for(int i = 1; i<=n; i++){ //본인 도시에서 본인도시로 가는 비용은 당연히 0.
        questionMap[i][i] = 0;
    }

    

    //n개의 도시 모두에 대해서 할건데, 시작 지점은 0, 도달 불가능해도 0.
    for(int i = 1; i<=n; i++){ //중간 노드 (거쳐갈 노드)

        for(int j = 1; j<=n; j++){ //시작노드
            for(int z = 1; z<=n; z++){ //도착노드
                if(questionMap[j][z] > questionMap[j][i] + questionMap[i][z]){
                    questionMap[j][z] = questionMap[j][i] + questionMap[i][z];
                }
            }
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){

            if(questionMap[i][j] >= 1e9)questionMap[i][j] = 0; //갈 수 없는 경우, 갱신.
            cout<<questionMap[i][j]<<" ";
        }
        cout<<"\n";
    }





    return 0;
}