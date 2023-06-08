#include <iostream>
#include <algorithm>

using namespace std;
int memo[1000000];

int main() {
    int T;
    cin >> T;

    for(int i = 2; i <= T; i++){
        memo[i] = memo[i - 1] + 1;

        if(i % 2 == 0)
            memo[i] = min(memo[i], memo[i/2] + 1);

        if(i % 3 == 0)
            memo[i] = min(memo[i], memo[i/3] + 1);
    }

    cout << memo[T];

    return 0;
}

// bottom-up 방식으로 DP를 구현한 문제.