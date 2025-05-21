#include <bits/stdc++.h>
using namespace std;

int N, M, K;

int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

struct fireBall {
    int y, x, m, s, d;
};

vector<fireBall> questionMap[51][51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int y, x, m, s, d;
        cin >> y >> x >> m >> s >> d;
        y--, x--;
        questionMap[y][x].push_back({ y, x, m, s, d });
    }

    while (K--) {
        // 1. 모든 파이어볼 이동
        vector<fireBall> movedBalls;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (auto f : questionMap[i][j]) {
                    int ny = (f.y + dy[f.d] * f.s % N + N) % N;
                    int nx = (f.x + dx[f.d] * f.s % N + N) % N;
                    movedBalls.push_back({ ny, nx, f.m, f.s, f.d });
                }
                questionMap[i][j].clear();
            }
        }

        for (auto f : movedBalls) {
            questionMap[f.y][f.x].push_back(f);
        }

        // 2. 병합 및 분할
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (questionMap[i][j].size() < 2) continue;

                int totalM = 0, totalS = 0;
                int cnt = questionMap[i][j].size();
                bool allEven = true, allOdd = true;

                for (auto f : questionMap[i][j]) {
                    totalM += f.m;
                    totalS += f.s;
                    if (f.d % 2 == 0) allOdd = false;
                    else allEven = false;
                }

                questionMap[i][j].clear();
                int newM = totalM / 5;
                if (newM == 0) continue;

                int newS = totalS / cnt;
                vector<int> newDirs = (allEven || allOdd) ? vector<int>{0,2,4,6} : vector<int>{1,3,5,7};

                for (int d : newDirs) {
                    questionMap[i][j].push_back({ i, j, newM, newS, d });
                }
            }
        }
    }

    // 3. 남은 파이어볼 질량 합
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (auto f : questionMap[i][j]) {
                ret += f.m;
            }
        }
    }

    cout << ret << '\n';
    return 0;
}
