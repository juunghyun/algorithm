#include <bits/stdc++.h>

using namespace std;

int N, K; // N : 0~10만, K : 0~10만

//N은 걷기-순간이동 두가지 선택 가능. -> 걷기 : +1 혹은 -1 위치. 순간이동 : 현재위치 x2
//N이 K를 찾는 가장 빠른 시간 구하기.
//대신, K보다 커진 좌표로 이동했으면 N-K한 시간만큼 더하고 큐에 집어넣지 않기. (갱신)
//방문한 좌표라면, 
// bfs -> 1. 
// 생각해보면, 다익스트라랑 비슷함. 왜? 갈 수 있는 노드 : +1 or -1 or 2.
// 근데 각 노드 별 도착 시간이 존재함. -> 그냥 bfs랑 다를게 없음. 


struct MyInfo{
    int distance;
    int pos;

    bool operator<(const MyInfo & other)const{
        return distance > other.distance;
    }
};


int main(){
    cin>>N>>K;

    int ret = 1e13;

    vector<int> visited(100001, 1e13);

    priority_queue<MyInfo> pq;

    visited[N] = 0;
    pq.push({0, N});

    while(!pq.empty()){
        int cur = pq.top().pos;
        int sec = pq.top().distance;
        pq.pop();

        if(cur == K){ // 만났으면
            ret = min(ret, sec);
            break;
        }

        if(cur>K){ // 더 큰 좌표에 있다면 뻗지 않기.
            ret = min(ret, sec + cur - K);
            continue;
        }

        if(sec > visited[cur]) continue; //이미 갱신된 좌표면 안가기.

        //목표 지점이 더 큰 경우만 남음.

        for(int i = 0; i<3; i++){
            if(i == 0){
                int nx = cur - 1;
                if(nx<0)continue;
                if(visited[nx] > sec + 1){
                    pq.push({sec + 1, nx});
                    visited[nx] = sec + 1;
                }
            }else if(i == 1){
                int nx = cur + 1;
                if(visited[nx]>sec + 1){
                    pq.push({sec + 1, nx});
                    visited[nx] = sec + 1;
                }
            }else{
                int nx = cur * 2;
                if(nx>100000)continue;
                if(visited[nx]>sec){
                    pq.push({sec, nx});
                    visited[nx] = sec;
                }
            }
        }
    }

    cout<< ret;

    return 0;
}