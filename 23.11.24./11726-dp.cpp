// 규칙성 못 찾았을 때는 차근차근 다시 생각하자..

#include <iostream>

using namespace std;

#define MAX 1001

int dp[MAX];
int N;

int main(){
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;

    for(auto i = 3; i <= N; i++){
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }

    cout << dp[N] << '\n';

    return 0;
}