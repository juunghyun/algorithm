#include <bits/stdc++.h>

using namespace std;

// 전역 변수 대신 함수 인자로 set을 전달하여 유일 조합을 추적
void find_sets(int k, 
               const vector<vector<string>>& temp_ids,
               const vector<string>& user_id,
               vector<bool>& visited_user, 
               set<vector<int>>& valid_sets) {
    
    // 종료 조건: 모든 banned_id에 대해 user_id를 선택했으면
    if (k == temp_ids.size()) {
        vector<int> current_set;
        for (int i = 0; i < visited_user.size(); i++) {
            if (visited_user[i]) {
                current_set.push_back(i);
            }
        }
        // 조합의 순서에 상관없이 같은 집합을 하나로 취급하기 위해 정렬 후 set에 삽입
        sort(current_set.begin(), current_set.end());
        valid_sets.insert(current_set);
        return;
    }
    
    // 현재 banned_id에 매칭되는 user_id 후보들을 순회
    for (const string& candidate_id : temp_ids[k]) {
        int candidate_idx = -1;
        // user_id 배열에서 후보의 인덱스 찾기
        for (int i = 0; i < user_id.size(); i++) {
            if (user_id[i] == candidate_id) {
                candidate_idx = i;
                break;
            }
        }
        
        // 해당 user_id가 아직 사용되지 않았다면 (백트래킹)
        if (candidate_idx != -1 && !visited_user[candidate_idx]) {
            // 선택
            visited_user[candidate_idx] = true;
            
            // 재귀 호출
            find_sets(k + 1, temp_ids, user_id, visited_user, valid_sets);
            
            // 백트래킹
            visited_user[candidate_idx] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    // 1. 각 banned_id에 매칭되는 user_id 후보들 찾기
    vector<vector<string>> temp_id(banned_id.size());
    for(int i = 0; i < banned_id.size(); i++){
        for(int j = 0; j < user_id.size(); j++){
            if (banned_id[i].size() == user_id[j].size()) {
                bool match = true;
                for(int z = 0; z < banned_id[i].size(); z++) {
                    if (banned_id[i][z] != '*' && banned_id[i][z] != user_id[j][z]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    temp_id[i].push_back(user_id[j]);
                }
            }
        }
    }

    // 2. 백트래킹을 위한 자료구조 선언
    vector<bool> visited_user(user_id.size(), false);
    set<vector<int>> valid_sets;

    // 3. 재귀 함수 호출
    find_sets(0, temp_id, user_id, visited_user, valid_sets);
    
    // 4. 유일한 조합의 개수 반환
    return valid_sets.size();
}