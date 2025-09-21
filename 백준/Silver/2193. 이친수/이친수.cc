#include <bits/stdc++.h>
using namespace std;


/**
 * 0과 1로만 이루어진 수를 이진수라 한다. 이러한 이진수 중 특별한 성질을 갖는 것들이 있는데, 
 * 이들을 이친수(pinary number)라 한다. 이친수는 다음의 성질을 만족한다.
 * 이친수는 0으로 시작하지 않는다.
 * 이친수에서는 1이 두 번 연속으로 나타나지 않는다. 즉, 11을 부분 문자열로 갖지 않는다.
 * 예를 들면 1, 10, 100, 101, 1000, 1001 등이 이친수가 된다. 
 * 하지만 0010101이나 101101은 각각 1, 2번 규칙에 위배되므로 이친수가 아니다.
 * N(1 ≤ N ≤ 90)이 주어졌을 때, N자리 이친수의 개수를 구하는 프로그램을 작성하시오.
 */
//완탐 : 딱봐도 불가능. 90자리에서 2자리 다 01 넣기 개빡셈
//dp로 해보기
using namespace std;

int N;
long long dp[91][2];

// solve(idx, lastNum): idx번째 자리에 lastNum이 올 때의 경우의 수
long long solve(int idx, int lastNum) {
    // 기저 조건: 1번째 자리까지 도달했을 때
    if (idx == 1) {
        // 첫번째 자리가 1이어야만 유효
        if (lastNum == 1) {
            return 1;
        } else {
            return 0; // 0으로 시작하면 안됨
        }
    }

    // 메모이제이션
    if (dp[idx][lastNum] != -1) {
        return dp[idx][lastNum];
    }
    
    long long count = 0;
    
    if (lastNum == 0) { //0이면 담에 암거나 오셈
        count += solve(idx - 1, 0) + solve(idx - 1, 1);
    }
    else { //1이면 0만 담에 오셈
        count += solve(idx - 1, 0);
    }

    return dp[idx][lastNum] = count;
}

int main() {
    cin >> N;
    
    memset(dp, -1, sizeof(dp));

    cout << solve(N, 0) + solve(N, 1) << "\n";

    return 0;
}