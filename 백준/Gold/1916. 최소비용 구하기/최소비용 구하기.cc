#include<bits/stdc++.h>
using namespace std;

int N; //1~1000 도시의 개수
int M; //1~10만 버스의 개수
//M줄간 버스 정보 : 출발도시 -> 도착도시 버스비용(0이상~10만미만)
//출발 도시에서 도착점 가는 최소 비용  출력.
//출발 도시, 도착 도시 : 맨 마지막 입력.

typedef long long ll;

ll startPos, endPos;

struct CityInfo{
    ll cityPos;
    ll distance;

    bool operator<(const CityInfo& other) const{ //거리가 가까운곳이 우선.
        return distance>other.distance;
    }
};

vector<pair<ll, ll>> adj[1001]; //갈 수 있는 도시, 거리

priority_queue<CityInfo> pq;

int main(){
    cin>>N>>M;

    //간선 정보 저장
    for(int i = 0; i<M; i++){
        int startTemp, endTemp, costTemp;
        cin>>startTemp>>endTemp>>costTemp;
        adj[startTemp].push_back({endTemp, costTemp});
    }

    vector<ll> dist(1001, 1e9); //간선 정보, 거리를 다 무한대로 변경

    cin>>startPos>>endPos;

    dist[startPos] = 0; //시작점 거리 0
    pq.push({startPos, dist[startPos]});

    while(!pq.empty()){
        CityInfo tempNow = pq.top();
        pq.pop();

        if(tempNow.distance > dist[tempNow.cityPos])continue; 

        for(auto k : adj[tempNow.cityPos]){ //갈 수 있는곳중에
            if(dist[k.first]> k.second + dist[tempNow.cityPos]){ //현재 탐색 도시 거리 + 가중치 거리가 현재 갈 곳의 거리보다 작다면?
                dist[k.first] = k.second + dist[tempNow.cityPos];
                pq.push({k.first, dist[k.first]});
            }
        }
    }

    cout<<dist[endPos]<<"\n";



    return 0;
}