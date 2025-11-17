#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main() {

    cin >> T;

    // 100+1+ 패턴과 01 패턴이  반복되는 정규식
    regex re("(100+1+|01)+");

    while (T--) {
        cin >> s;

        if (regex_match(s, re))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}
