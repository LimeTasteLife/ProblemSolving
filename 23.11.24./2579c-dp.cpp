// DP 문제는 난이도와 상관없이 늘 낯설다
// 점화식을 세우는 연습을 많이 안해봐서 그럴 것이다.
// 출처: https://tooo1.tistory.com/218 [개발자 퉁이리:티스토리]

#include <iostream>

using namespace std;
#define MAX 301

int N;
int stairs[MAX];
int dp[MAX];

int main() {
    cin >> N;

    for(auto i=0;i<N;i++) 
        cin >> stairs[i];
    
    dp[0] = stairs[0];
    dp[1] = max(stairs[1],stairs[0]+stairs[1]);
    dp[2] = max(stairs[0] + stairs[2],stairs[1]+stairs[2]);

    for(auto i=3;i<N; i++) 
        dp[i] = max(stairs[i] + dp[i-2], stairs[i]+stairs[i-1] +dp[i-3]);

    cout << dp[N-1];
}
