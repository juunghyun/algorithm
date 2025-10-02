#include<bits/stdc++.h>

using namespace std;
/**
* 모든 경우는 "가능한" 경우만 들어옴
* k : 1~10^12 / 배열 크기 : 200000 최대 / 배열 원소값 : 1~k
* Map으로 최대한 오버헤드를 줄이자.
*/

unordered_map<long long, long long> myMap;

long long find(long long idx){
    
    if(myMap.find(idx) == myMap.end()){
        return idx;
    }else{
        return myMap[idx] = find(myMap[idx]); //갱신하면서 리턴
    }
}


vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    //메인 로직
    for(long long i = 0; i<room_number.size(); i++){
        long long startTemp = find(room_number[i]); // 이방으로 주세요.
        answer.push_back(startTemp); //줄게요?
        myMap[startTemp] = startTemp + 1; //이방 달라하면 이제 다른방 주시길
    }

    return answer;
}