#include <bits/stdc++.h>

using namespace std;

int N;
int maxDp[2][3]; // 0, 1 행만 사용 (메모리 최적화)
int minDp[2][3];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;

    // DP 테이블 초기화
    memset(maxDp, 0, sizeof(maxDp));
    // minDp는 0으로 초기화하면 안 될 수 있으나 (모든 입력이 0~9 양수이므로 괜찮음)
    // 0번 행만 0으로 초기화하는 것이 더 명확합니다.
    memset(minDp[0], 0, sizeof(minDp[0]));
    memset(minDp[1], 0, sizeof(minDp[1]));


    for(int i = 1; i <= N; i++){
        int v0, v1, v2;
        cin >> v0 >> v1 >> v2;

        // 2. 'check' 변수 대신 인덱스 직접 계산 (버그 수정)
        // i=1일 때: cur=1, prev=0
        // i=2일 때: cur=0, prev=1
        // i=3일 때: cur=1, prev=0
        int cur = i % 2;  // 현재 계산할 행 (0 또는 1)
        int prev = (i - 1) % 2; // 참조할 이전 행 (0 또는 1)

        // 3. 'j' 루프 제거 (가독성 향상)
        // 0번 칸 계산
        maxDp[cur][0] = max(maxDp[prev][0], maxDp[prev][1]) + v0;
        minDp[cur][0] = min(minDp[prev][0], minDp[prev][1]) + v0;

        // 1번 칸 계산
        maxDp[cur][1] = max({maxDp[prev][0], maxDp[prev][1], maxDp[prev][2]}) + v1;
        minDp[cur][1] = min({minDp[prev][0], minDp[prev][1], minDp[prev][2]}) + v1;

        // 2번 칸 계산
        maxDp[cur][2] = max(maxDp[prev][1], maxDp[prev][2]) + v2;
        minDp[cur][2] = min(minDp[prev][1], minDp[prev][2]) + v2;
    }
    
    // 최종 결과가 저장된 행 (N=1이면 1, N=2이면 0, N=3이면 1...)
    int final_row = N % 2; 

    cout << max({maxDp[final_row][0], maxDp[final_row][1], maxDp[final_row][2]}) << " ";
    cout << min({minDp[final_row][0], minDp[final_row][1], minDp[final_row][2]});

    return 0;
}