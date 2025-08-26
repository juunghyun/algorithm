#include<bits/stdc++.h>
using namespace std;

int questionMap[9][9];

bool checkFunc(int y, int x, int checkNum){
    // 행 검사
    for(int i = 0; i < 9; i++){
        if(questionMap[y][i] == checkNum) return false;
    }

    // 열 검사
    for(int i = 0; i < 9; i++){
        if(questionMap[i][x] == checkNum) return false;
    }

    // 3x3 박스 검사
    int startY = (y / 3) * 3;
    int startX = (x / 3) * 3;
    for(int i = startY; i < startY + 3; i++){
        for(int j = startX; j < startX + 3; j++){
            if(questionMap[i][j] == checkNum) return false;
        }
    }
    
    return true;
}

bool solv(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(questionMap[i][j] == 0){
                for(int num = 1; num <= 9; num++){
                    if(checkFunc(i, j, num)){
                        questionMap[i][j] = num;

                        if (solv()) {
                            return true; // 재귀 성공 -> 즉시 종료
                        }
                        
                        questionMap[i][j] = 0; // 백트래킹
                    }
                }
                //답이 없는 경우
                return false; 
            }
        }
    }
    
    //완성
    return true;
}

void printMap() {
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << questionMap[i][j];
        }
       cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 9; i++){
        string inputs;
        cin >> inputs;
        for(int j = 0; j < 9; j++){
            questionMap[i][j] = inputs[j] - '0';
        }
    }

    solv();
    printMap();

    return 0;
}