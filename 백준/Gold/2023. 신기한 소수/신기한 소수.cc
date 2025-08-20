/**
 * 7331
 * 7331은 소수인데, 신기하게도 733도 소수이고, 73도 소수이고, 7도 소수이다. 
 * 즉, 왼쪽부터 1자리, 2자리, 3자리, 4자리 수 모두 소수이다! 수빈이는 이런 숫자를 신기한 소수라고 이름 붙였다.
 * 수빈이는 N자리의 숫자 중에서 어떤 수들이 신기한 소수인지 궁금해졌다. 
 * N이 주어졌을 때, 수빈이를 위해 N자리 신기한 소수를 모두 찾아보자.
 * 
 * 1. 2 3 5 7 로 시작하는 세계선 준비
 * 2. 뒤에 1 3 5 7 9 즉 홀수가 되는 숫자들 붙여보기
 * 3. 해당 수가 소수인지 검사
 * 3-1 소수면, 2로 가기
 * 3-2 소수가 아니면 넘어가기
 * 4 N자리수가 완성됐다면, 해당 수를 vector에다가 넣기
 * 5. vector sort 후 출력
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> specialNum;
int backNum[5] = {1,3,5,7,9};

bool isDec(int n){
    int baseNum = sqrt(n);

    for(int i = 3; i<=baseNum; i++){
        //나눠지면 소수 아님
        if(n%i == 0)return false;
    }

    return true;
}

void go(int n, int depth){
    // 여기에 들어왔다는건 n이 소수라는 뜻

    //종료조건
    if(depth == N){
        specialNum.push_back(n);
        return;
    }

    for(int i = 0; i<5; i++){
        int checkNum = n*10 + backNum[i];
        if(isDec(checkNum))go(checkNum, depth + 1);
    }
    return;
}

int main(){
    cin>>N;

    go(2, 1);
    go(3, 1);
    go(5, 1);
    go(7, 1);

    sort(specialNum.begin(), specialNum.end());

    for(auto k : specialNum){
        cout<<k<<"\n";
    }

    return 0;
}

