#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    int result = 0;
    for(int i = 0; i< T; i++){
        int n;
        cin >> n;

        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(n % j == 0){
                cnt++;
            }
        }
        if(cnt == 2 ){
            result++;
        }
    }

    cout << result << endl;
    return 0;
}