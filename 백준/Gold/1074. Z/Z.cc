#include <bits/stdc++.h>


//2의 제곱수인 N, NxN 지도 z모양 탐색.
//z모양 탐색을 하는데요, 특정 좌표를 몇번째로 방문하는지 출력하라.
//입력값 : N r c (r,c)몇번째로 방문함?

//지도에서, 우선 N이 2의 몇제곱 몇인지를 알아햠. 이게 N으로 주어지니까, 
// N이 1인 경우에 어떻게하냐? Z 패턴. 실제로 방문은 여기서 함.

//-> 1차 시도 틀림. 왜? 시간초과. 왜? 완탐을 안해도 되는 문제인데 완탐해서.
//완탐 안하면 어떻게함? 2^15 * 2 ^ 15 는 당연히 일단 시간초과나는데, 이걸 간과함.
//-> 어떻게할건데요? 몇사분면인지 파악해서 해당하는 숫자만큼 더해주기.

using namespace std;

long long N, r, c;

long long func(int y, int x, int N){

    
    if(N == 0){ //해당 좌표에 도착했네요.
        return 0;
    }

    long long half = 1LL << (N - 1);
    long long q_size = half * half;

    //좌표가 몇사분면임?
    if(y<half && x<half){ //2
        return 0 + func(y, x, N-1);
    }else if(y<half && x>=half){ //1'
        return q_size + func(y, x - half, N-1);
    }else if(y>= half && x<half){ //3
        return 2*q_size + func(y - half, x, N-1);
    }else{ //4
        return 3*q_size + func(y - half, x - half, N-1);
    }


}


int main(){
    cin>>N>>r>>c;

    cout<<func(r, c, N);

    return 0;
}