#include <bits/stdc++.h>
using namespace std;

int L, C; //암호 크기 / 알파벳 개수
vector<char> cV;
map<char, int> mp;

void go(vector<char> v, int depth){

    if(v.size()==L){ //개수 다채웠나요
        string retS;
        int check1 = 0;
        for(auto k : v){
            retS += k;
            if(mp[k]){ //모음 체크
                check1++; 
            }
        }

        if(check1 && L-check1 >= 2){
            cout<<retS<<"\n";
        }
        return;
    }

    
    for(int i = depth; i<C; i++){
        v.push_back(cV[i]);
        go(v, i+1); //선택도 하고 레벨도 올리기
        v.pop_back();
    }

    return;
}

int main(){
    cin>>L>>C;
    for (int i = 0; i < C; i++)
    {
        char inputChar;
        cin>>inputChar;
        cV.push_back(inputChar);
    }

    mp['a'] = 1;
    mp['e'] = 1;
    mp['o'] = 1;
    mp['u'] = 1;
    mp['i'] = 1;

    sort(cV.begin(), cV.end());

    vector<char> clearV;
    go(clearV, 0);

    return 0;
}