#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int N;
    cin >> N;

    float num[N];
    for(int i = 0; i < N; i++)
        cin >> num[i];

    sort(num, num + N);

    int max = num[N-1];
    float sum = 0;
    for(int i = 0; i < N; i++){
        num[i] = num[i] / max * 100;
        sum += num[i];
    }

    sum = sum / N;

    cout << sum << endl;

    return 0;
}