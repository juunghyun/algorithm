#include<bits/stdc++.h>
using namespace std;

//좌측상단의 좌표 + 길이를 줘야할듯.

int N;
int zeroTwoArr[2]; //0에는 0개수, 1에는 1개수.

void func(int y, int x, int N, vector<vector<int>> & questionMap){

    int checkNum = questionMap[y][x]; //이 숫자랑 똑같은지 확인하죠.

    if(N == 1){
        zeroTwoArr[questionMap[y][x]]++;
        return;
    }

    for(int i = y; i<N+y; i++){
        for(int j = x; j<N+x; j++){
            if(questionMap[i][j]!= checkNum){ //다른순간 4분할.
                func(y, x, N/2, questionMap);
                func(y, x + N/2, N/2, questionMap);
                func(y + N/2, x, N/2, questionMap);
                func(y + N/2, x + N/2, N/2, questionMap);
                return;
            }
        }
    }

    zeroTwoArr[checkNum]++;


    return;
}

int main(){
    cin>>N;

    vector<vector<int>> questionMap(N, vector<int> (N));

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>questionMap[i][j];
        }
    }

    func(0, 0, N, questionMap);

    for(auto k : zeroTwoArr){
        cout<<k<<"\n";
    }


    return 0;
}