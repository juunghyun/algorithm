#include <bits/stdc++.h>
using namespace std;

// struct a{
//     int mynum;
//     int rate;
//     int time;
// };
vector<pair<int, int>> v; //숫자, 들어온 횟수
map<int, int> mp; //숫자, 들어온 횟수
map<int, int> rating; //숫자, 들어온 등수

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second==b.second){ //빈도수 똑같다면
    return rating[a.first]<rating[b.first]; //등수 낮은걸로
    }else{ //빈도수 다르면
    return a.second>b.second;
    }
}

int N,C;
int inputnum;

int main(){
    cin>>N>>C;

    for(int i = 1; i<=N; i++){
        cin>>inputnum;
        mp[inputnum]++;
        if(rating[inputnum]==0){
            rating[inputnum] = i;
        }
    }

    for(auto k : mp){
        v.push_back({k.first, k.second});
    }

    sort(v.begin(), v.end(), cmp);

    for(auto k : v){
        for(int i = 0; i<k.second; i++){
            cout<<k.first<<" ";
        }
    }



    return 0;
}