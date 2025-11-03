#include <bits/stdc++.h>

int N, M;
//크기 N 배열, M개 이하 구간으로 나눠서, 구간의 점수의 최대값-> 최소로 하고자 함.
//구간의 점수란? 최대값 - 최소값 차이.
//15462137 -> 15 462 137로 나누면, 각 구간의 점수 : 4 4 6이 됨.
// 156 621 37 로나누면 4 5 4 로 최대값 5가 됨.

//구간 점수의 최댓값의 최솟값을 구하라.. 즉 아까 4 5 4 처럼 5 이렇게 가장 큰 수가 젤 낮게 나오도록 해라.

//-> binary search임. 최댓값의 최솟값을 구하는거보니.
//그럼, 구간 점수 -> 이걸 옮겨다녀야함. 구간 점수를 1부터 올려가면서 해야할듯?
//구간점수의 최대가 1일때, 1 한개 가능.1,5 안되니까, 나누고, 5,4가능 6안되니까, 나눔. 6, 2 안되니까, 실패
// -> 구간점수를, left = mid로 해서 다시하기..
//이런식으로 해야할듯?

//M : 구간 개수 최대치 개수

using namespace std;

bool check(int mid, const vector<int> & questionArr){

    int maxNum = -987654321;
    int minNum = 987654321;
    int cnt = M-1; //구간 나눌 수 있는 횟수
    
    for(int i = 0; i<N; i++){
        //이번 항 들어오면서, 최대, 최소값 갱신.
        maxNum = max(questionArr[i], maxNum);
        minNum = min(questionArr[i], minNum);

        if(maxNum - minNum >mid){ //최대 - 최소를 하는데, 이게 mid보다 크면 안됨.즉, 나눠야 하는 상황.
            cnt--; //나누기.

            if(cnt<0){//횟수 이미 다썼다?
                return false;
            }
            //최대, 최소값 갱신.
            maxNum = questionArr[i];
            minNum = questionArr[i];
        }

    }


    return true;
}

int main(){
    cin>>N>>M;
    vector<int> questionArr(N);
    int ret = 987654321;

    //배열 주어짐.
    for(int i = 0; i<N; i++){
        cin>>questionArr[i];
    }

    int left = 0; //배열의 크기가 1일 경우, 한개면 최대값 - 최소값 = 0이므로. 0스타트
    int right = 9999; //배열 안에 수가 1~10000 이므로 최대는 9999.

    while(left<=right){
        int mid = (left + right)/2;
        if(check(mid, questionArr)){ //true : 현재 값으로 가능하니까 조금 더 내려보죠.
            ret = min(ret, mid);
            right = mid - 1;
        }else{// 이거 안되니까 올려야함
            left = mid + 1;
        }
    }

    cout<<ret<<"\n";



    return 0;
}