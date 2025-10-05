#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<vector<int>> sets;
    string num = "";
    vector<int> temp;

    for (int i = 1; i < (int)s.size() - 1; i++) {
        char c = s[i];
        if (isdigit(c)) {
            num += c;
        } 
        else if (c == ',') {
            if (!num.empty()) {
                temp.push_back(stoi(num));
                num = "";
            }
        } 
        else if (c == '}') {
            if (!num.empty()) {
                temp.push_back(stoi(num));
                num = "";
            }
            if (!temp.empty()) {
                sets.push_back(temp);
                temp.clear();
            }
        }
    }

    // 원소 개수 기준으로 정렬
    sort(sets.begin(), sets.end(), [](auto &a, auto &b) {
        return a.size() < b.size();
    });

    vector<int> answer;
    unordered_set<int> seen;

    for (auto &v : sets) {
        for (int x : v) {
            if (seen.find(x) == seen.end()) {
                seen.insert(x);
                answer.push_back(x);
            }
        }
    }

    return answer;
}
