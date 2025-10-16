#include <bits/stdc++.h>
using namespace std;


const int maxNum = 64;
char questionArr[maxNum][maxNum];
string s;
int N;

string quadTree(int y, int x, int size){
    if(size == 1){return string(1,questionArr[y][x]);}
    char test = questionArr[y][x]; //기준
    string ret = ""; //답 담을 문자열
    for(int i = y; i < y + size; i++){ //기준 y, x 좌표에서 size 크기만큼 반복.
        for(int j = x; j < x + size; j++){
            if(test!=questionArr[i][j]){
                ret += '(';
                ret += quadTree(y, x, size/2); //2사분면
                ret += quadTree(y, x + size/2, size/2); //1사분면
                ret += quadTree(y + size/2, x, size/2); //3사분면
                ret += quadTree(y + size/2, x + size/2, size/2); //4사분면
                ret += ')';
                return ret;
                }
        }
    }
    return string(1,questionArr[y][x]);
    
}

int main(){
    cin>>N;

    for(int i = 0; i< N; i++){ //지도 넣기
        cin>>s;
        for(int j = 0; j < N; j++){
            questionArr[i][j]=s[j];
        }
    }

    cout<<quadTree(0,0,N);


    return 0;
}