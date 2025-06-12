/*
N개의 랜선을 만들어야함
K개의 랜선이 있음. N개의 같은 길이의 랜선으로 만들거임.
K개의 랜선을 잘라서 만들어야함
300짜리 랜선에서 140짜리 두개 잘라내면 20은 버려야함. 자른건 못붙임.
무조건 n개 만들 수 있음. 정수단위로 자름
가지고 있는 랜선의 개수 / 필요한 랜선의 개수 주어짐
필요한 랜선의 개수는 언제나 가진 랜선의 수 이상

먼저 가진 랜선의 개수 / 필요한 랜선 개수 주어짐
이후 이미 가진 랜선의 길이가 주어짐

N개 만들 수 있는 랜선의 최대 길이 출력
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, K;
ll ret;
ll myLen[10004];

bool check(ll n){
    if (n == 0) return false;
    ll temp = 0;
    for(int i = 0; i<K; i++){
        temp += (myLen[i]/n);
    }
    return N<=temp;
}

int main(){
    cin>>K>>N;

    ll maxLen = 0;

    for(int i = 0; i<K; i++){
        cin>>myLen[i];
        maxLen = max(maxLen, myLen[i]);
    }

    ll left = 1;
    ll right = maxLen;
    ret = 0;
    
    while(left<=right){
        ll mid = (left + right) / 2; //길이

        if(check(mid)){
            ret = mid;
            left = mid + 1;
        }else{
            right = mid-1;
        }

    }

    cout<<ret<<"\n";

    return 0;
}