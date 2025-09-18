#include <iostream>
#include <vector>

using namespace std;

// 10억으로 나눈 나머지 계산을 위한 상수
const int MOD = 1000000000;

int N;
vector<vector<long long>> dp;

// idx: 남은 자리 수, num: 현재 자리의 숫자
long long func(int idx, int num) {
    // 기저 조건: 남은 자리가 0일 때, 유효한 계단 수이므로 1을 반환
    if (idx == 0) {
        return 1;
    }
    
    // 이미 계산된 값이 있으면 반환 (메모이제이션)
    if (dp[idx][num] != -1) {
        return dp[idx][num];
    }
    
    long long count = 0;
    
    // 이전 숫자가 num-1인 경우 (0보다 커야 함)
    if (num > 0) {
        count = (count + func(idx - 1, num - 1)) % MOD;
    }
    
    // 이전 숫자가 num+1인 경우 (9보다 작아야 함)
    if (num < 9) {
        count = (count + func(idx - 1, num + 1)) % MOD;
    }
    
    // 계산된 값을 dp 테이블에 저장하고 반환
    return dp[idx][num] = count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    
    // dp 테이블을 N+1 x 10 크기로 만들고 -1로 초기화
    dp.assign(N + 1, vector<long long>(10, -1));

    long long result = 0;
    
    // 첫 번째 자리 숫자가 1~9인 경우로 시작 (0으로 시작하는 계단 수는 없으므로)
    for (int i = 1; i <= 9; ++i) {
        result = (result + func(N - 1, i)) % MOD;
    }

    cout << result << "\n";

    return 0;
}