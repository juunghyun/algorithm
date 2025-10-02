#include <bits/stdc++.h>

using namespace std;
/**
*
* 징검다리 : 1열. 각 돌에 숫자 있음(밟을때마다 -1)
* 돌의 숫자가 0이되면 못밟음. 
* 다음으로 밟을 수 있는 디딤돌이 여러개? -> 무조건 "가까운" 디딤돌로만 뛰셈.
* 디딤돌 배열 stones / k : 한번데 뛸 수 있는 디딤돌의 최대 칸수.
* 즉 stones를 싹다 1씩 줄이고, 검사를 하는데, 0이 K번 반복된다? 못건너는거임.이걸 검사하면될듯
* -> 시간초과남. 이분탐색 해보자. stones의 최소값 ~ 최대값 1/2해가지고 검사, 안대면ㄱㄱ
* 하면서 찾으면 그수가 답이니까.
*/

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = 1;
    int right = 200000000;
    
    while(left<=right){
        int mid = (left + right)/2;
        
        int checkNum = 0;
        int maxCheckNum = 0;
        
        for(int i = 0; i<stones.size(); i++){
            if(stones[i]-mid <= 0){
                checkNum++;
                maxCheckNum = max(checkNum, maxCheckNum);
            }else{
                checkNum = 0;
            }
        }
        
        if(maxCheckNum<k){ //건널수있어?
            answer = mid;
            left = mid + 1;
        }else{ //못건너?
            right = mid - 1;
        }
        
    }    
    
    
    return answer+1;
}