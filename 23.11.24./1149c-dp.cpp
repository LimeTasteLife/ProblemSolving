// 흠 어떻게 문제를 조각내서 풀까 그 디자인을 잘 해야한다.

#include <iostream>

using namespace std;

#define MAX 1001
int dp[MAX][3];
int cost[3];
int T;

int main(){
    cin >> T;

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    for(int i = 1; i <= T; i++){
        cin >> cost[0] >> cost[1] >> cost[2];

        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[2];
    }

    cout << min(dp[T][0], min(dp[T][1], dp[T][2])) << '\n';

    return 0;
}

