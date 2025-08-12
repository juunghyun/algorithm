/**
 * 
 * 백준 2206
 * 벽 부수고 이동하기
 * N M 지도
 * 0 이동 가능 / 1 벽
 * (0,0)->(N-1,M-1)이동 (최단경로, 시작과 끝도 셈)
 * 이동 도중에 벽 최대 1개 부수고 가도 됨.
 * 최단거리 출력.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// 전역 변수 선언
int N, M;
int questionMap[1004][1004]; // 입력받을 지도
int visited[1001][1001][2]; 
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int bfs() {
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0}); // 시작점 (0,0), 벽 아직 안 부숨(0)
    visited[0][0][0] = 1; // 시작하는 칸도 거리에 포함하므로 1로 초기화

    while (!q.empty()) {
        int y, x, broken;
        tie(y, x, broken) = q.front();
        q.pop();

        if (y == N - 1 && x == M - 1) {
            return visited[y][x][broken];
        }

        // 4. 네 방향으로 다음 상태 탐색
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 맵 범위를 벗어나는지 확인
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

            // Case 1: 다음 칸이 길(0)이고, 아직 방문하지 않았다면
            // 현재의 '벽 파괴 상태'를 그대로 유지하며 이동
            if (questionMap[ny][nx] == 0 && visited[ny][nx][broken] == 0) {
                visited[ny][nx][broken] = visited[y][x][broken] + 1;
                q.push({ny, nx, broken});
            }
            
            // Case 2: 다음 칸이 벽(1)이고, 아직 벽을 부순 적이 없다면('broken == 0')
            // '벽을 부순 상태'로 변경하여 이동
            else if (questionMap[ny][nx] == 1 && broken == 0) {
                // visited[...][1]에 방문 기록이 없는지 확인
                if (visited[ny][nx][1] == 0) {
                    visited[ny][nx][1] = visited[y][x][0] + 1;
                    q.push({ny, nx, 1}); // 벽을 부쉈으므로 상태를 1로 변경
                }
            }
        }
    }

    // 5. 큐가 비었는데 목표에 도달하지 못했다면 -1 반환
    return -1; 
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // N, M 입력
    cin >> N >> M;
    // 지도 정보 입력
    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < M; ++j) {
            questionMap[i][j] = row[j] - '0';
        }
    }

    // BFS 실행 및 결과 출력
    cout << bfs() << "\n";

    return 0;
}