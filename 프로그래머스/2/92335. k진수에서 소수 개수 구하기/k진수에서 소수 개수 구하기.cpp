#include<bits/stdc++.h>

/**
* n을 k진수로 바꿀건데요
* 변환된 수 안에 소수가 몇개인지 알아보자~ 단, 조건이 있슴.
* 1. 소수 양쪽에 '0' 이 있는 경우
* 2. 소수 왼쪽에 0이있고 오른쪽에 아무것도 없는 경우. 즉 k^0 의 자리에 소수가 오고 왼쪽에 0.
* 3. 소수 양쪽에 아무것도 없는경우
* 4. 이 모든 조건은, 자릿수에 0을 포함하지 않는 소수일 것.
* 기본 생각
* 1. 일단 어떤 숫자를 K진수로 바꾼 "문자열"을 리턴
* 2. 그리고 해당 문자열 0을 기준으로 split
* 3. split된 문자열 소수판별
* 4. 소수라면 + 1


*/

using namespace std;

string convertToBaseK(int n, int k) {
    if (n == 0) {
        return "0";
    }
    string result = "";
    while (n > 0) {
        result += to_string(n % k);
        n /= k;
    }
    reverse(result.begin(), result.end());
    return result;
}

bool isPrime(long long n) {
    if (n <= 1) {
        return false;
    }
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string temp = convertToBaseK(n, k);
    
    
    for(char & c : temp){ //0을 공백으로 치환
        if(c == '0'){
            c = ' ';
        }
    }
    
    stringstream ss(temp);
    string token;
    
    while(ss >> token){
        if(!token.empty()){
            long long tempNum = stoll(token);
            if(isPrime(tempNum)){
                answer++;
            }
        }
    }
    

    
 
       
    
    return answer;
}