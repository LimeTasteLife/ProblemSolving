#include <iostream>

using namespace std;
int fibo[41][2];

int main() {
    int T;
    cin >> T;

    int N;
    fibo[0][0] = 1;
    fibo[0][1] = 0;
    fibo[1][0] = 0;
    fibo[1][1] = 1;

    for(int i = 0; i < T; i++){
        cin >> N;
        if(N == 0){
            cout << "1 0" << endl;
            continue;
        }else if(N == 1){
            cout << "0 1" << endl;
            continue;
        }
        for(int i = 2; i <= N; i++){
            fibo[i][0] = fibo[i-1][0] + fibo[i-2][0];
            fibo[i][1] = fibo[i-1][1] + fibo[i-2][1];
        }
        cout << fibo[N][0] << ' ' << fibo[N][1] << endl;
    }

    return 0;
}