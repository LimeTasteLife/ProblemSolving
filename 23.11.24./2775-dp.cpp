// DP의 메커니즘을 이해하자!

#include <iostream>

using namespace std;

#define MAX 15

int T;
int k;
int N;
int dp[MAX][MAX];

int main(){
    cin >> T;

    for(auto i=1; i<=14; i++){
        dp[0][i] = i;
    }

    for(auto i=1; i<=14; i++){
        for(auto j=1; j<=14; j++){
            if(j == 1){
                dp[i][1] = dp[i-1][1];
            }
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }

    while(T--){
        cin >> k;
        cin >> N;

        cout << dp[k][N] << '\n';
    }

    return 0;
}