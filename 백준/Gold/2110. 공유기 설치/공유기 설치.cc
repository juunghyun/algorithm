#include <bits/stdc++.h>
using namespace std;
int N, C, inputn;
vector<int> housePoint;
int ret = 0;

bool check(int mid){ //mid : 인접한 두 공유기 사이의 거리. 생각해보면 처음과 마지막은 무조건 설치해야함.

    //맨 앞 wifi 무조건 설치했다고 생각
    int betweenDistance = 0;
    int cnt = C - 1; //설치해야하는 공유기 남은 숫자.

    //mid만큼 떨어지면서 설치하는게 가능한지 확인
    for(int i = 1; i<housePoint.size(); i++){ //2번쨰 칸~ 마지막 전칸까지 확인
        betweenDistance += housePoint[i]-housePoint[i-1];
        if(betweenDistance >= mid){
            cnt--; //공유기 하나 설치
            betweenDistance = 0;
        }
    }

    if(cnt>0){ //해당 간격으로는 설치 불가능
        return false;
    }

    //가능하다면
    ret = max(ret, mid);
    return true;
}

int main(){
    cin>>N>>C;

    int left = INT_MAX;
    int right = INT_MIN;
    for(int i = 0; i<N; i++){
        cin>>inputn;
        housePoint.push_back(inputn);
    }

    sort(housePoint.begin(), housePoint.end());

    for(int i = 1; i<housePoint.size(); i++){
        left = min(left, housePoint[i]-housePoint[i-1]);
    }

    right = housePoint[housePoint.size()-1] - housePoint[0];

    while(left<=right){
        int mid = (left+right)/2;

        if(check(mid)){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    cout<<ret<<'\n';

    return 0;
}