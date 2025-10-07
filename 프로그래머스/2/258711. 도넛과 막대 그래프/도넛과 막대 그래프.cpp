#include <bits/stdc++.h>

using namespace std;
/**
* 그래프들이 여러개 있음, 이 그래프와 무관한 정점 하나 생성 후 각 도넛, 막대, 8자 그래프의 임의의 정점 하나로 향하는 간선 연결함. (모든 그래프들로 이동 가능)
* 그래프의 간선 정보가 주어짐. 생성한 정점의 번호와 각 그래프 타입의 개수를 
* 정점 번호, 도넛모양,막대모양,8자모양 순서로 개수를 담아 배열로 리턴 ㄱ
*/

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    map<int, pair<int, int>> vertexMap; // pair : out, in
    
    int startPos = -1;
    int startOutNum = 0;
    int type8Num = 0;
    int typeDonutNum = 0;
    int typeLineNum = 0;
    
    for(vector<int> k : edges){
        vertexMap[k[0]].first++;
        vertexMap[k[1]].second++;
    }
    
    for(auto k : vertexMap){
        int tempPos = k.first;
        pair<int, int> tempNum = k.second;
        
        if(tempNum.first >=2 && tempNum.second == 0){ //시작정점
            startPos = tempPos;
        }else if(tempNum.first==2 && tempNum.second>=2){ //나가는게 2개고 들어오는게 2개이상 : 8
            type8Num++;
        }else if(tempNum.first == 0 && tempNum.second>=1){ //나가는게 0개고 들어오는게 1개이상 : 막대
            typeLineNum++;
        }
    }
    
    startOutNum = vertexMap[startPos].first;
    
    typeDonutNum = startOutNum - (type8Num + typeLineNum);
    
    answer.push_back(startPos);
    answer.push_back(typeDonutNum);
    answer.push_back(typeLineNum);
    answer.push_back(type8Num);
    
    
    return answer;
}