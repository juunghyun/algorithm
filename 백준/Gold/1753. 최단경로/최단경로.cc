#include <bits/stdc++.h>
using namespace std;

int V, E; //정점의 개수(20000 이하), 간선의 개수(300000 이하)
int K; //시작 정점 노드번호.

struct NodeInfo{
    int distance;
    int nodeIdx;

    bool operator <(const NodeInfo& other) const{ //작은게 앞에 오도록.
        return distance > other.distance;
    }
};


int main(){
    cin>>V>>E>>K;
    vector<pair<int, int>> nodeV[V+1]; //도착지점, 거리
    vector<int> dist(V+1, 1e9); //각 정점 별 거리 상황.
    dist[K] = 0; //시작지점 비용 초기화

    //간선 정보 저장
    for(int i = 0; i<E; i++){
        int startNode, endNode, distanceTemp;
        cin>>startNode>>endNode>>distanceTemp;
        nodeV[startNode].push_back({endNode, distanceTemp});
    }

    priority_queue<NodeInfo> pq;
    pq.push({0, K});
    while(!pq.empty()){
        NodeInfo tempNI = pq.top();
        pq.pop();

        for(auto k : nodeV[tempNI.nodeIdx]){ //갈 수 있는 모든곳
            if(tempNI.distance + k.second < dist[k.first]){ //가려는곳이 거리가 비용이 더 작아진다면?
                dist[k.first] = tempNI.distance + k.second; //해당 비용으로 변경해주고
                pq.push({dist[k.first], k.first});
            }
        }
    }

    for(int i = 1; i<=V; i++){
        if(dist[i]==1e9){
            cout<<"INF\n";
        }else{
            cout<<dist[i]<<"\n";
        }
    }


    return 0;
}