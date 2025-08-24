#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> v;
int result = 0;

/**
 * checkNum 정수가 좋은 수인지 확인하는 메서드
 * 해당 수가 "다른 두 수"의 합으로 나타낼 수 있어야 함.
 * -2 -1 -1 0 0 0 1 2 3 이라고 하면, -2, -1, -1, 0, 0, 0, 1, 2, 3 모두 좋은 수다..
 * 그냥 전체 다 이분탐색 돌리는게 현명할지도.
 */
void checkFunc(int checkNum, int banned){ 
    int left = 0;
    int right = N-1;

    if(left == banned) left++;
    if(right ==banned) right--;

    while(left<right){
    
        if(v[left]+v[right] < checkNum){
            left++;
            if(left == banned) left ++;
        }else if(v[left] + v[right] > checkNum){
            right--;
            if(right == banned) right --;
        }else{
            result++;
            return;
        }
    }
    return;
}

int main(){
    cin>>N;

    for(int i = 0; i<N; i++){
        int inputn;
        cin>>inputn;
        v.push_back(inputn);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i<N; i++){
        checkFunc(v[i], i);
    }

    cout<<result<<"\n";

    return 0;
}