#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 36진수 문자를 0-35 정수로 변환
int char_to_int(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return c - 'A' + 10;
    }
}

// 0-35 정수를 36진수 문자로 변환
char int_to_char(int v) {
    if (v >= 0 && v <= 9) {
        return v + '0';
    } else {
        return v - 10 + 'A';
    }
}

// 이 문제에서는 BigInt를 36진수 자릿값의 벡터로 표현합니다.
// (인덱스 0이 36^0, 인덱스 1이 36^1 ...)
using BigInt = vector<int>;

// BigInt의 뒤쪽(높은 자릿수)에 있는 불필요한 0을 제거
void normalize(BigInt& a) {
    while (a.size() > 1 && a.back() == 0) {
        a.pop_back();
    }
}

// BigInt 덧셈 (Base 36)
BigInt add(const BigInt& a, const BigInt& b) {
    BigInt res;
    int carry = 0;
    int n = a.size();
    int m = b.size();

    for (int i = 0; i < max(n, m) || carry; ++i) {
        int sum = carry;
        if (i < n) sum += a[i];
        if (i < m) sum += b[i];

        res.push_back(sum % 36);
        carry = sum / 36;
    }
    return res;
}

// BigInt와 작은 정수의 곱셈 (Base 36)
BigInt multiply_by_int(BigInt a, int k) {
    if (k == 0) return {0};
    
    int carry = 0;
    // long long을 사용해 중간 계산 시 오버플로 방지
    for (int i = 0; i < a.size() || carry; ++i) {
        if (i == a.size()) a.push_back(0); // 자릿수 확장
        
        long long cur = (long long)a[i] * k + carry;
        a[i] = cur % 36;
        carry = cur / 36;
    }
    normalize(a);
    return a;
}

// BigInt 대소 비교 (a < b)
bool compare(BigInt a, BigInt b) {
    normalize(a);
    normalize(b);
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    // 가장 높은 자릿수(vector의 끝)부터 비교
    for (int i = a.size() - 1; i >= 0; --i) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return false; // 두 수가 같음
}

// BigInt 출력 (Base 36)
void print_bigint(BigInt a) {
    normalize(a);
    if (a.empty() || (a.size() == 1 && a[0] == 0)) {
        cout << "0\n";
        return;
    }
    for (int i = a.size() - 1; i >= 0; --i) {
        cout << int_to_char(a[i]);
    }
    cout << "\n";
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // Weight[i]: 값 i (0~35)를 가진 문자가 등장한 모든 자릿수(36^p)의 합
    vector<BigInt> Weight(36, {0});
    BigInt TotalSum = {0}; // 아무것도 바꾸지 않았을 때의 총합

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        
        BigInt P = {1}; // P는 현재 자릿값 (36^0, 36^1, ...)

        // 문자열의 뒤(1의 자리)부터 순회
        for (int j = s.length() - 1; j >= 0; --j) {
            int val = char_to_int(s[j]);
            
            // 1. 초기 총합에 (현재 값 * 자릿값)을 더함
            TotalSum = add(TotalSum, multiply_by_int(P, val));
            
            // 2. 해당 문자의 가중치(Weight)에 현재 자릿값을 더함
            Weight[val] = add(Weight[val], P);
            
            // 3. 다음 자릿수로 (P = P * 36)
            P = multiply_by_int(P, 36);
        }
    }

    int K;
    cin >> K;

    // Gains[i]: 값 i를 'Z'(35)로 바꿨을 때의 '이득'
    // 이득 = (35 - i) * Weight[i]
    vector<pair<BigInt, int>> Gains;
    for (int i = 0; i < 36; ++i) {
        if (i == 35) continue; // 'Z'는 'Z'로 바꿔도 이득이 없음
        BigInt gain = multiply_by_int(Weight[i], 35 - i);
        Gains.push_back({gain, i});
    }

    // 이득(gain)을 기준으로 내림차순 정렬
    sort(Gains.begin(), Gains.end(), [](const pair<BigInt, int>& a, const pair<BigInt, int>& b) {
        // b < a 를 반환하여 내림차순 정렬
        return compare(b.first, a.first);
    });

    // 상위 K개의 이득을 TotalSum에 더함
    for (int i = 0; i < K && i < Gains.size(); ++i) {
        TotalSum = add(TotalSum, Gains[i].first);
    }

    // 최종 결과 출력
    print_bigint(TotalSum);

    return 0;
}