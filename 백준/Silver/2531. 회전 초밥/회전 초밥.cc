#include <bits/stdc++.h>

using namespace std;

int N, d, k, c;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> d >> k >> c;

    // 1. 배열 확장: N개의 원본 초밥 배열 생성
    vector<int> sushi(N);
    for (int i = 0; i < N; i++) {
        cin >> sushi[i];
    }
    
    // 배열을 두 배로 확장 (k-1개만 추가하여 슬라이딩 윈도우 처리)
    // N번 인덱스부터 N+k-2까지의 데이터가 원형 구조를 처리해 줌.
    for (int i = 0; i < k - 1; i++) {
        sushi.push_back(sushi[i]); 
    }
    
    // 초밥 종류별 개수 기록 배열 (1부터 d까지 사용)
    vector<int> sushiCnt(d + 1, 0);
    // 현재 윈도우 내의 초밥 종류 수

    int current_kinds = 0;
    int max_kinds = 0;

    // 2. 초기 윈도우 설정 (0부터 k-1까지)
    for (int j = 0; j < k; j++) {
        int type = sushi[j];
        sushiCnt[type]++;
    }

    //3. 쿠폰 적용 무조건 되니깐
    sushiCnt[c]++;

    for(auto k : sushiCnt){
        if(k>0)current_kinds++;
    }

    max_kinds = current_kinds;


    // 윈도우의 시작점 i가 N-1까지 이동하면 모든 N가지 경우를 탐색함.
    for (int i = 1; i < N; i++) {
        
        // A. 제거 (Out): 윈도우에서 나가는 초밥 (i-1)
        int out_type = sushi[i - 1];
        sushiCnt[out_type]--;
        if (sushiCnt[out_type] == 0) {
            current_kinds--; // 종류가 0이 되었으므로 종류 수 감소
        }

        // B. 추가 (In): 윈도우에 새로 들어오는 초밥 (i + k - 1)
        int in_type = sushi[i + k - 1]; 
        sushiCnt[in_type]++;
        if (sushiCnt[in_type] == 1) { // 0에서 1이 되었으므로
            current_kinds++; // 새로운 종류 추가
        }
        

        max_kinds = max(max_kinds, current_kinds);
    }

    // 5. 결과 출력
    cout << max_kinds << "\n";

    return 0;
}