#include <bits/stdc++.h>

//N개의 노드 트리
//M개의 두 노드 쌍, 두 노드 사이의 거리 출력 gogo
//근데 노드 사이의 가중치가 다 다르다.
//N, M 받고 N-1개동안 간선정보 들어옴. 두 점과 거리.
//-> 즉 각 간선의 가중치가 다름.
//간선 다 받고 거리를 알고 싶은 M개의 노드 쌍이 주어짐.
//둘의 거리를 출력 gogo
//N : 2~1000, M : 1~1000, 간선의 가중치 : 1만이하 

using namespace std;

struct Node{
    int pos;
    int dis;

    bool operator<(const Node& other) const{
        return dis>other.dis;
    }
};

int N, M;
//N : 1000이므로 모든 최단거리 : 1000000000 10억? -> 플로이드 워셜 안됨.

int main(){

    cin>>N>>M;

    vector<pair<int,int>> nodeV[N+1]; //간선 정보 저장

    //간선정보
    for(int i = 0; i<N-1; i++){
        int node1, node2, dis;
        cin>>node1>>node2>>dis;
        nodeV[node1].push_back({node2, dis});
        nodeV[node2].push_back({node1,dis});
    }


    for(int i = 0; i<M; i++){

        int startNode, endNode;
        cin>>startNode>>endNode;

        vector<int> dist(1001, 1e9);
        priority_queue<Node> pq;

        dist[startNode] = 0;
        pq.push({startNode, dist[startNode]});

        while(!pq.empty()){
            Node tempNode = pq.top();
            pq.pop();

            if(tempNode.dis>dist[tempNode.pos]) continue;

            for(auto k : nodeV[tempNode.pos]){ //갈 수 있는 노드정보
                if(dist[k.first]>k.second + dist[tempNode.pos]){//해당 거리가 더 작아진다면 갱신
                    dist[k.first] = k.second + dist[tempNode.pos];
                    pq.push({k.first, dist[k.first]});
                } 
            }
        }

        cout<<dist[endNode]<<"\n";
    }


    return 0;
}
