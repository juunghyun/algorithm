#include<bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0; //사라진 인형의 개수
    int n = board.size();
    stack<int> stk;

    
    for(int i = 0; i<moves.size(); i++){
        int y = 0;
        int x = moves[i]-1;
        
        
        while(true){
            if(board[y][x]!=0){ //해당 칸에 인형이 있는 경우
                int tempDoll = board[y][x];
                board[y][x] = 0; //해당 칸 인형 뽑았음
                
                if(!stk.empty()){//비어있지 않다면 체크
                    int vsTop = stk.top();
                    if(vsTop == tempDoll){
                        stk.pop(); //지워짐!
                        answer+=2; //지웠으니까 +1점
                    }else{
                        stk.push(tempDoll); //있긴한데 다르면 넣기
                        
                    }
                }else{//비어있다면
                    stk.push(tempDoll);//비어있으면 걍 넣기
                    
                }
                
                
                break;
            }
            
            if(y==n-1){//바닥인경우
                break;
            }
            
            y++; //아직 더 갈수있으면 내려가기
        }
        
        
    }
    
    
    return answer;
}