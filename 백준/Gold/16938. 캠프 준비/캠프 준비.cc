#include<bits/stdc++.h>

using namespace std;

int N, L, R, X; //N : 문제 개수, i번째 문제의 난이도 : Ai.
//문제 난이도의 합 : L이상 R이하. 가장 어려운 문제 난이도 - 쉬운 문제 난이도 는 X이상.

//문제 세트를 고를 수 있는 방법의 수를 계산 ㄱㄱ
//난이도합 5이상 6이하이므로 -> 2 3 / 1 2 3 두개가 되는데, 둘다 난이도 차이가 1, 2 이고 X가 1이므로 가능.
//문제의 개수 : 15. -> 2^15는 3만번 언저리이므로 백트래킹 가능 ->(고른다 안고른다.)
int ret = 0;

bool checkFunc(const vector<int> & v , const vector<int> & question){
    if((int)v.size()>=2){

        int sumTemp = 0; //난이도 합계
        int maxTemp = -1e9;
        int minTemp = 1e9;

        for(auto k : v){
            sumTemp += question[k];
            maxTemp = max(maxTemp, question[k]);
            minTemp = min(minTemp, question[k]);
        }

        int Xtemp = maxTemp - minTemp; //난이도 차이

        if(L <= sumTemp && sumTemp <= R && Xtemp>=X){ //난이도 합계는 L이상 R이하.
            return true;
        }
    }

    return false; //그 외에는 다 안됨.
}


void func(int idx, vector<int> & v, const vector<int> & question){ //현재 idx, 고른 셋
    
    if(idx == N + 1){ //다 골랐네요 첨부터 끝까지?
        // 현재 set이 캠프에 사용될 수 있는지 파악.
        if(checkFunc(v, question)){
            ret++;
        }

        return;
    }

    //다 고르기 전.

    vector<int> tempV = v; //현재 고른 문제 풀 받아오고
    func(idx + 1, tempV, question); //그냥 가기
    tempV.push_back(idx); //현재 문제 풀에 넣기
    func(idx + 1, tempV, question); //넣은 세계선
    


    return;
}





int main(){
    cin>>N>>L>>R>>X;
    vector<int> question(N + 1);

    //문제별 난이도
    for(int i = 1; i<=N; i++){ 
        cin>>question[i];
    }


    vector<int> v;

    func(1, v, question); //1번부터 고를지 말지 결정해~


    cout<<ret<<"\n";

    return 0;
}