#include <iostream>

using namespace std;

int diff(string a, string b);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;

        string str[N+1];
        for(int i = 0; i < N; i++){
            cin >> str[i];
        }

        if( N > 32){
            // 비둘기집의 원리. 33명 이상이면 무조건 똑같은 MBTI는 3개 등장한다.
            cout << '0' << '\n';
            continue;
        }

        int minNum = 10000;
        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++ ){
                for(int k = j+1; k < N; k++){
                    int distance = diff(str[i], str[j]) + diff(str[j], str[k]) + diff(str[i], str[k]);
                    minNum = min(minNum, distance);
                }
            }
        }

        cout << minNum << '\n';
    }

    return 0;
}

int diff(string a, string b){
    int num = 0;

    // mbti가 다르면, diff증가.
    for(int i = 0; i < 4; i++){
        if(a[i] != b[i])
            num++;
    }

    return num;
}