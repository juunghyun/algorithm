/**
 * 백준 17135번: 캐슬 디펜스
 * 최종 풀이 (직관적인 방법 적용)
 */
#include <bits/stdc++.h>

using namespace std;

// 전역 변수 선언
int N, M, D;
vector<pair<int, int>> enemyV; // 초기 적 위치 저장용
int maxKillNum = 0;

// 두 지점 사이의 맨해튼 거리를 계산하는 함수
int dis(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

// 궁수 한 명이 쏠 최적의 타겟을 찾는 헬퍼(helper) 함수
// (궁수 열 위치, 현재 적 목록) -> 타겟 좌표
pair<int, int> findBestTarget(int archerCol, const vector<pair<int, int>>& enemies) {
    int min_dist = D + 1; // 공격 가능 거리(D)보다 큰 값으로 초기화
    pair<int, int> target_pos = {-1, -1}; // 타겟 없음 상태

    for (const auto& enemy : enemies) {
        int d = dis({N, archerCol}, enemy);

        if (d > D) continue; // 공격 거리 밖이면 무시

        if (d < min_dist) {
            // 1. 더 가까운 적을 발견하면 무조건 타겟으로 삼음
            min_dist = d;
            target_pos = enemy;
        } else if (d == min_dist) {
            // 2. 거리가 같다면 더 왼쪽에 있는 적(열 번호가 작은)을 타겟으로 삼음
            if (target_pos.second > enemy.second) {
                target_pos = enemy;
            }
        }
    }
    return target_pos;
}

// 한 번의 게임 시뮬레이션을 수행하는 함수
void game(int archer1_col, int archer2_col, int archer3_col) {
    // 1. 시뮬레이션 환경 준비
    vector<pair<int, int>> enemyTempV = enemyV; // 이번 게임에서 사용할 적, 원본 복사
    int killNum = 0;

    // 2. 게임 진행 (맵에 적이 없을 때까지)
    while (!enemyTempV.empty()) {
        
        // ========== 턴 시작: 궁수 공격 ==========
        
        // 각 궁수가 쏠 타겟을 찾음
        vector<pair<int, int>> targetEnemies;
        targetEnemies.push_back(findBestTarget(archer1_col, enemyTempV));
        targetEnemies.push_back(findBestTarget(archer2_col, enemyTempV));
        targetEnemies.push_back(findBestTarget(archer3_col, enemyTempV));

        // 공격받을 고유한 적 목록을 만듦 (set으로 중복 제거)
        set<pair<int, int>> killedEnemiesSet;
        for (const auto& target : targetEnemies) {
            if (target.first != -1) { // 유효한 타겟(공격할 적이 있는 경우)만 추가
                killedEnemiesSet.insert(target);
            }
        }

        // 이번 턴에 잡은 적 수만큼 총 킬 수 증가
        if (!killedEnemiesSet.empty()) {
            killNum += killedEnemiesSet.size();

            // 살아남은 적들만 골라서 새로운 벡터에 담는다.
            vector<pair<int, int>> survivingEnemies;
            for (const auto& enemy : enemyTempV) {
                // 현재 적(enemy)이 제거 대상 목록(killedEnemiesSet)에 없으면 생존자
                if (killedEnemiesSet.find(enemy) == killedEnemiesSet.end()) {
                    survivingEnemies.push_back(enemy);
                }
            }
            // 적 목록을 생존자 목록으로 교체
            enemyTempV = survivingEnemies;
        }

        // ========== 턴 종료: 적 이동 ==========
        
        // 살아남은 적들을 아래로 한 칸씩 이동
        vector<pair<int, int>> nextTurnEnemies;
        for (const auto& p : enemyTempV) {
            int newRow = p.first + 1;
            if (newRow < N) { // 성에 도달하지 않은 적만 다음 턴에 살아남음
                nextTurnEnemies.push_back({newRow, p.second});
            }
        }
        // 다음 턴의 적 목록으로 교체
        enemyTempV = nextTurnEnemies;
    }

    // 3. 시뮬레이션 종료 후, 최대 킬 수 갱신
    maxKillNum = max(killNum, maxKillNum);
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 받기
    cin >> N >> M >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int cell;
            cin >> cell;
            if (cell == 1) {
                enemyV.push_back({i, j});
            }
        }
    }

    // M개의 열 중 3개의 궁수 위치를 뽑는 모든 조합 실행
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            for (int k = j + 1; k < M; k++) {
                game(i, j, k);
            }
        }
    }

    // 최종 결과 출력
    cout << maxKillNum << "\n";

    return 0;
}