#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int a[N];

    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    sort(a, a + N);

    int sum;
    int dif = M+1;
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            for(int k = j+1; k < N; k++){
                sum = a[i] + a[j] + a[k];
                int tmp = M - sum;
                if(tmp < 0){
                    continue;
                }
                if(tmp < dif){
                    dif = tmp;
                    ans = sum;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}