/**
 * 1 ~ 10억 : 산성 용액 / -1 ~ -10억 : 알칼리 용액
 * 용액의 특성값이 쭉 주어짐
 * 딱 두개 골라서 0에 가까운 수 출력하기
 * -> **정렬 후** left, right 가장 왼쪽, 오른쪽 에 두고 옮기기
 */


#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> v;

int main(){
    cin>>N;

    for(int i = 0; i<N; i++){
        int inputn;
        cin>>inputn;
        v.push_back(inputn);
    }
    

    sort(v.begin(), v.end());

    int left = 0;
    int right = N-1;
    int temp = INT_MAX;
    pair<int, int> tempPos = {INT_MIN, INT_MAX};

    while(left<right){

        //즉시종료조건
        if(v[left] + v[right] == 0){
            tempPos = {v[left], v[right]};
            break;
        }

        //갱신
        if(abs(v[left] + v[right])<temp){
            temp = abs(v[left] + v[right]);
            tempPos = {v[left], v[right]};
        }

        if(v[left] + v[right]< 0){
            left += 1;
        }else{
            right -= 1;
        }

    }

    cout<<tempPos.first<<" "<<tempPos.second;

    return 0;
}