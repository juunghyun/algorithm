#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring> // for memset

using namespace std;

// 전역 변수로 사전 데이터 관리 (메모리 넉넉함)
string words[200005];
int wordCounts[200005][26]; // 각 단어의 알파벳 카운트 미리 저장
int wordCount = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. 사전 입력 및 전처리
    while (true) {
        string s;
        cin >> s;
        if (s == "-") break;
        
        words[wordCount] = s;
        for (char c : s) {
            wordCounts[wordCount][c - 'A']++;
        }
        wordCount++;
    }

    // 2. 퍼즐 입력 및 해결
    while (true) {
        string puzzle;
        cin >> puzzle;
        if (puzzle == "#") break;

        int puzzleCharCnt[26] = {0};
        for (char c : puzzle) {
            puzzleCharCnt[c - 'A']++;
        }

        // 중앙 글자가 (A~Z)일 때 만들 수 있는 단어의 개수
        int score[26] = {0}; 
        
        // 모든 사전을 한 번만 순회
        for (int i = 0; i < wordCount; i++) {
            bool possible = true;
            
            // 2-1. 이 단어를 퍼즐판으로 만들 수 있는지 확인
            // (단어의 길이 조건 등은 이미 입력 조건에 부합한다고 가정하거나 여기서 체크)
            for (int j = 0; j < 26; j++) {
                if (wordCounts[i][j] > puzzleCharCnt[j]) {
                    possible = false;
                    break;
                }
            }

            // 2-2. 가능하다면, 이 단어에 포함된 문자들의 점수 증가
            if (possible) {
                // 이 단어에 포함된 알파벳들을 확인 (중복 제외)
                // 예: 단어가 "TTL"이면 T와 L의 점수를 올려줌
                // 왜냐? T가 중앙일 때도 "TTL" 가능, L이 중앙일 때도 "TTL" 가능하니까.
                for (int j = 0; j < 26; j++) {
                    if (wordCounts[i][j] > 0) {
                        score[j]++;
                    }
                }
            }
        }

        // 3. 결과 계산 (최소/최대 찾기)
        int minCnt = 200001, maxCnt = -1;
        string minChars = "", maxChars = "";

        // 퍼즐판에 존재하는 문자들에 대해서만 답을 구해야 함
        // 퍼즐에 'A'가 없는데 A를 중앙에 둘 순 없으니까요.
        int visited[26] = {0}; // 이미 확인한 문자인지 체크 (퍼즐판에 L이 2개여도 L은 한 번만 출력)

        for (char c : puzzle) {
            int idx = c - 'A';
            if (visited[idx]) continue;
            visited[idx] = 1;

            int cnt = score[idx]; // 해당 문자가 중앙일 때 가능한 단어 수

            if (cnt < minCnt) {
                minCnt = cnt;
                minChars = ""; // 초기화
                minChars += c;
            } else if (cnt == minCnt) {
                minChars += c;
            }

            if (cnt > maxCnt) {
                maxCnt = cnt;
                maxChars = ""; // 초기화
                maxChars += c;
            } else if (cnt == maxCnt) {
                maxChars += c;
            }
        }

        // 출력 조건: 알파벳순 정렬 (이미 loop 순서나 string append 순서 고려 필요하지만, sort가 안전)
        sort(minChars.begin(), minChars.end());
        sort(maxChars.begin(), maxChars.end());

        cout << minChars << " " << minCnt << " " << maxChars << " " << maxCnt << "\n";
    }

    return 0;
}