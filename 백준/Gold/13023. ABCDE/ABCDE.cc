/**
 *  N명 참가 (0 ~ N-1번)
 * 
 * A는 B와 친구다.
 * B는 C와 친구다.
 * C는 D와 친구다.
 * D는 E와 친구다.
 * 이런 친구관계 있는지 탐색하라
 * 첫째 줄에 사람의 수 N (5 ≤ N ≤ 2000)과 친구 관계의 수 M (1 ≤ M ≤ 2000)이 주어진다.
 * 둘째 줄부터 M개의 줄에는 정수 a와 b가 주어지며, a와 b가 친구라는 뜻이다. 
 * (0 ≤ a, b ≤ N-1, a ≠ b) 같은 친구 관계가 두 번 이상 주어지는 경우는 없다.
 * 
 * 존재시 1, 없을 시 0 출력
*/

#include <bits/stdc++.h>
using namespace std;

int N, M;
bool check = false;
vector <int> friendship[2000];
int visited[2000];

void bfs(int cur, int depth){

    if(depth == 4) {
        check = true;
        return;
    }

    visited[cur] = 1;
    for(auto k : friendship[cur]){
        if(visited[k]==0)bfs(k, depth + 1);
    }
    visited[cur] = 0;
}

int main(){
    cin>>N>>M;

    for(int i = 0; i<M; i++){
        int a, b;
        cin>>a>>b;
        friendship[a].push_back(b);
        friendship[b].push_back(a);
    }

    for(int i = 0; i<1996; i++){
        bfs(i, 0);
        if(check)break;
    }

    if(check){
        cout<<1<<"\n";
    }else{
        cout<<0<<"\n";
    }
    
    return 0;
}