#include <bits/stdc++.h>

/**
*
* 각 유저 : 한번에 한명 신고
* 한 유저 여러번 신고 가능, 하지만 한 유저가 동일한 유저 여러번 신고해봤자 1회로 처리됨
* k번 이상 신고된 유저 : 게시판 이용 정지. 해당 유저 신고한 유저에게 메일 발송.
* k번 신고된 순간이 아닌, 모두 취합했을 때 k번 이상인 경우 발송..
* [idx]가 신고한 사람과 [idx]가 신고받은 사람을 두개 운용
* 한 사람이 중복? 의미없음 -> unordered_set사용
* 이렇게 되는데 각 유저별로 처리 결과 메일 받는 횟수를 answer에 담기.
* id_list : idx처리용
* report : 문자열 파싱해서 신고한 사람/받은사람 두개 배열에 넣기
* result에다가 idx처리해서 report로만든 두 배열 바탕으로 넣기.
*/
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    map<int, unordered_set<int>> reportTo; //int 인덱스 사람이 신고한 사람
    map<int, unordered_set<int>> reportFrom; //int 인덱스 사람을 신고한 사람
    
    for(int i = 0; i<report.size(); i++){
        string tempS = report[i];
        string firstUser = "";
        string secondUser = "";
        firstUser = tempS.substr(0, tempS.find(' '));
        secondUser = tempS.substr(tempS.find(' ')+1);
        
        int firstUserIdx;
        int secondUserIdx;
        for(int i = 0; i<id_list.size(); i++){
            if(id_list[i]==firstUser){
                firstUserIdx = i;
            }else if(id_list[i]==secondUser){
                secondUserIdx = i;
            }
        }
        
        reportTo[firstUserIdx].insert(secondUserIdx);
        reportFrom[secondUserIdx].insert(firstUserIdx);
    
    }
    
    //정지 될 사람 찾기 : reportFrom의 개수가 k이상
    vector<int> bannedIdx; //정지 대상의 idx가 들어감.
    
    for(int i = 0; i< id_list.size(); i++){
        if(reportFrom[i].size()>=k){
            bannedIdx.push_back(i);
        }
    }
    
    for(int i = 0; i<id_list.size(); i++){
        unordered_set<int> tempReportTo = reportTo[i];
        //tempReportTo에 포함되는 idx가 있나요?
        for(int j = 0; j<bannedIdx.size(); j++){
            if(tempReportTo.find(bannedIdx[j])!=tempReportTo.end()){
                answer[i]++;
            }
        }
        
    }
    

    
    
    
    
    
    
    
    
    
    return answer;
}