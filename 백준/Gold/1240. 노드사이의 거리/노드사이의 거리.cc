#include<bits/stdc++.h>

struct Node{
    int pos;
    int dis;

    bool operator<(const Node& other)const{
        return dis>other.dis;
    }
};

using namespace std;

int N, M;

int main(){

    cin>>N>>M;
    vector<pair<int, int>> nodeV[N+1];

    //간선 정보 저장
    for(int i = 0; i<N-1; i++){
        int node1, node2, dis;
        cin>>node1>>node2>>dis;
        nodeV[node1].push_back({node2, dis});
        nodeV[node2].push_back({node1, dis});
    }


    for(int i = 0; i<M; i++){
        int startNode, endNode;
        cin>>startNode>>endNode;

        vector<int> dist(N+1, 1e9);
        priority_queue<Node> pq;
        dist[startNode] = 0;
        pq.push({startNode, dist[startNode]});

        while(!pq.empty()){
            Node tempNode = pq.top();
            pq.pop();

            //노드에 있는 거리보다 갱신된 값이 있다면 ㄴㄴ
            if(tempNode.dis>dist[tempNode.pos])continue;

            //큐에서 나온 정점에서 갈 수 있는 목록 k : {갈 수 있는 정점, 거리};
            for(auto k : nodeV[tempNode.pos]){ 
                if(dist[k.first]>tempNode.dis + k.second){
                    dist[k.first] = tempNode.dis + k.second;
                    pq.push({k.first, dist[k.first]});
                }
            }
        }

        cout<<dist[endNode]<<"\n";
    }

    return 0;
}